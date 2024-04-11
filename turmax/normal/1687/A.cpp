#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int pr[n+1]={0};for(int i=0;i<n;++i) pr[i+1]=pr[i]+a[i];
        int ans=0;int k1=min(k,n);
        for(int i=0;i<=n-k1;++i) {ans=max(ans,pr[i+k1]-pr[i]);}
        if(k<n) {cout<<ans+k*(k-1)/2<<'\n';}
        else if(n!=1) {
            int sum=0;for(int i=0;i<n;++i) sum+=(a[i]+k-1);
            cout<<(sum-n*(n-1)/2)<<'\n';
        }
        else
        {
            cout<<a[0]+k-1<<'\n';
        }
    }
    return 0;
}