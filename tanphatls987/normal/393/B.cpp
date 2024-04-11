#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    float a[170][170],b[170][170],w[170][170];
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) cin>>w[i][j];
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            a[i][j]=(float(w[i][j]+w[j][i]))/2;
            a[j][i]=a[i][j];
            b[i][j]=w[i][j]-a[i][j];
            if (i!=j) b[j][i]=-b[i][j];
        }
    for(i=0;i<n;i++)
        {for(j=0;j<n;j++) printf("%.2f ",a[i][j]);printf("\n");}
    for(i=0;i<n;i++)
        {for(j=0;j<n;j++) printf("%.2f ",b[i][j]);printf("\n");}
}