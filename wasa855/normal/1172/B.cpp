#include<bits/stdc++.h>
using namespace std;
#define int long long
int dgr[200005];
#define mod 998244353
signed main()
{
    int n;
    cin>>n;
    int u,v;
    int ans=n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        dgr[u]++,dgr[v]++;
        ans=ans*dgr[u]%mod*dgr[v]%mod;
    }
    cout<<ans<<endl;
    return 0;
}