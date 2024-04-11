#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,x;cin>>n>>x;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int pr[n+1];pr[0]=0;for(int i=0;i<n;++i) pr[i+1]=pr[i]+a[i];
        int ans[n];for(int i=0;i<n;++i) ans[i]=(-1e18);
        for(int i=0;i<n;++i) for(int j=(i+1);j<=n;++j) ans[j-i-1]=max(ans[j-i-1],pr[j]-pr[i]);
        for(int k=0;k<=n;++k) {int res=0;for(int i=0;i<n;++i) {res=max(res,ans[i]+x*min(i+1,k));} cout<<res<<' ';}
        cout<<'\n';
    }
    return 0;
}