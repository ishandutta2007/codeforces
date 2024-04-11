#include <iostream>
using namespace std;
int main()
{
    int a[100]={0},xo,yo,x,i,j,y,n,ans;
    cin>>n;
    cin>>xo>>yo;
    for(i=xo;i<yo;i++) a[i]=1;
    for(i=2;i<=n;i++)
    {
        cin>>x>>y;
        for(j=x;j<y;j++) a[j]=0;
    }
    ans=0;
    for(i=xo;i<yo;i++) ans+=a[i];
    cout<<ans;
}