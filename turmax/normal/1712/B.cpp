#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int ans[n+1];for(int i=1;i<=n;++i) ans[i]=i;
        for(int i=n-1;i>=1;i-=2)
        {
            swap(ans[i],ans[i+1]);
        }
        for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}