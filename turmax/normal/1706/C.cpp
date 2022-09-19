#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
    int b[n]={0};b[0]=1e18;b[n-1]=1e18;for(int i=1;i<n-1;++i) {b[i]=max({0LL,a[i-1]-a[i]+1,a[i+1]-a[i]+1});}
    if(n%2==1)
    {
        int sum=0;for(int i=1;i<n;i+=2) {sum+=b[i];}
        cout<<sum<<'\n';
    }
    else
    {
        int pr[n+2]={0};pr[1]=b[1];
        for(int i=2;i<n-1;++i) pr[i]=pr[i-2]+b[i];
        int ans=1e18;for(int i=2;i<=n;i+=2) {if(i!=2) ans=min(ans,pr[n-2]-pr[i-2]+pr[i-3]); else ans=min(ans,pr[n-2]-pr[i-2]);}
        cout<<ans<<'\n';
    }
    }
    return 0;
}