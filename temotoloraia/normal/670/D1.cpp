#include <iostream>
using namespace std;
int n,k,a[100001],b[100001],i,j,x,ans,q,p;
main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>b[i];
    for (j=1;j<=n;j++)
        cin>>a[j];
    for (ans=1;true;ans++){
            p=0;
        for (i=1;i<=n;i++)
        if (a[i]<ans*b[i])
            p+=ans*b[i]-a[i];
    if (k==p)
        break;
    if (k<p){
        ans--;
        break;
    }
    }
    cout<<ans<<endl;
}