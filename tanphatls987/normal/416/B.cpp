#include <iostream>

using namespace std;

int main()
{
    long int m,n,a[50000][5],i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++) cin>>a[i][j];
    for(i=1;i<n;i++) a[0][i]=a[0][i]+a[0][i-1];
    for(i=1;i<m;i++) a[i][0]=a[i][0]+a[i-1][0];
    for(i=1;i<m;i++)
        for(j=1;j<n;j++) a[i][j]=a[i][j]+(a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1]);
    for(i=0;i<m;i++) cout<<a[i][n-1]<<" ";
}