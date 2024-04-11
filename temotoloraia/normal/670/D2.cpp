#include <iostream>
using namespace std;
long long n,k,a[100001],b[100001],i,j,x,ans,q,p,pas,l=1,r=2000000000;
main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>b[i];
    for (j=1;j<=n;j++)
        cin>>a[j];
    while (l<=r){
            p=0;
            ans=(l+r)/2;
        for (i=1;i<=n;i++)
        if (a[i]<1ll*ans*b[i]){
            p+=ans*b[i]-a[i];
            if (p>k)
            break;
        }
    if (k>=p){
        pas=max(pas,ans);
        l=ans+1;
    }
    if (k<p)
        r=ans-1;
    }
    cout<<pas<<endl;
}