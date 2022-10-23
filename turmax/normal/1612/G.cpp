#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e6+5;
int d[2*maxn];int fact[2*maxn];int inv2=(p+1)/2;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<2*maxn;++i) {fact[i]=(fact[i-1]*i)%p;}
    int n;cin>>n;int a[n];for(int i=0;i<n;++i) {cin>>a[i];d[a[i]+maxn+1]--;d[1-a[i]+maxn]++;}
    int ways=1;int ans=0;int cur=0;
    for(int i=2;i<2*maxn;++i)
    {
        d[i]+=d[i-2];
    }
    for(int i=0;i<2*maxn;++i) {ans+=(((i-maxn)*d[i])%p)*(2*cur+d[i]);ans%=p;cur+=d[i];cur%=p;ways*=fact[d[i]];ways%=p;}
    ans*=inv2;ans%=p;
    cout<<(ans%p+p)%p<<' '<<(ways%p+p)%p;
    return 0;
}