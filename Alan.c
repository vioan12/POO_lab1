#include"Alan.h"

FILE *file;
void citire()
{
    file=fopen("in.txt","r");
    fscanf(file,"%d%d",&n,&r);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(file,"%f",&a[i][j]);
    fclose(file);
}

void afisare()
{
    file=fopen("out.txt","w");
    fprintf(file,"%d\n%d",n,r);
    for(int i=0;i<n;i++){
        fprintf(file,"\n");
        for(int j=0;j<n;j++)
            fprintf(file,"%f ",a[i][j]);
    }
    fclose(file);
}

void ridicare_la_putere()
{
    int a_temp[100][100],b[100][100],sum;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a_temp[i][j]=a[i][j];
    for(int ct=1;ct<r;ct++){
        for(int l=0;l<n;l++)
            for(int p=0;p<n;p++)
                b[l][p]=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                sum=0;
                for(int j=0;j<n;j++)
                    sum=sum+a[i][j]*a_temp[j][k];
                b[i][k]=sum;
            }
        }
        for(int l=0;l<n;l++)
            for(int p=0;p<n;p++)
                a[l][p]=b[l][p];
    }
}

