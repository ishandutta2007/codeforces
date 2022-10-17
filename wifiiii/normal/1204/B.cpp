#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int b[25],sum[25];
int32_t main()
{
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<=20;++i) b[i]=(1<<i);
    sum[0]=1;
    for(int i=1;i<=20;++i) sum[i]=sum[i-1]+b[i];
    ll ans1=0;
    if(l<=n) ans1=sum[l-1]+n-l;
    else ans1=sum[l-1];
    ll ans2=0;
    if(r<=n) ans2=sum[r-1]+b[r-1]*(n-r);
    else ans2=sum[r-1];
    cout<<ans1<<" "<<ans2<<endl;
}