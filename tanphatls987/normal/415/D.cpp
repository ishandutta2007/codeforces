#include <iostream>
using namespace std;

const long int module=1000000007;
int main()
{
    int64_t ans;
    long int a[2][2001]={0},n,i,j,k,m,x;
    cin>>n>>k;
    for(i=1;i<=n;i++) a[0][i]=1;
    long int crow=0;
    for(i=1;i<k;i++)
    {
        crow=1-crow;
        for(j=1;j<=n;j++) a[crow][j]=a[1-crow][j];
        for(j=1;j<=n;j++)
        { for(m=j+j;m<=n;m+=j) a[crow][m]=(a[crow][m]+a[1-crow][j])%module;}
    }
    ans=0;
    for(i=1;i<=n;i++) ans=(ans+a[crow][i])%module;
    cout<<ans;
}