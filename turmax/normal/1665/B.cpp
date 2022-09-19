#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int x,int y)
{
    if(x<=0) return 0;
    if(x<=y) return 1;
    return f(x-y,2*y)+1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];for(auto &h:a) cin>>h;
        map <int,int> cnt;for(auto h:a) cnt[h]++;
        int ans=1e18;
        for(auto [key,val]:cnt)
        {
            int ans1=(n-val+f(n-val,val));
            ans=min(ans,ans1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}