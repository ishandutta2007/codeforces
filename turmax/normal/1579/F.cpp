#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv(vector <int> v)
{
    bool ok=1;for(auto h:v) ok=(ok && h);
    if(ok) return 1e18;
    vector <int> g=v;
    for(auto h:v) g.push_back(h);
    vector <int> t;
    for(int i=0;i<g.size();++i) if(g[i]==0) t.push_back(i);
    int ans=0;
    for(int i=0;i<t.size()-1;++i) ans=max(ans,t[i+1]-t[i]-1);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int o=__gcd(n,d);
        vector <int> b[o];
        int ans=0;
        for(int i=0;i<o;++i)
        {
            int curr=i;
            while(true)
            {
                b[i].push_back(a[curr]);
                curr+=d;
                curr%=n;
                if(curr==i) break;
            }
            ans=max(ans,slv(b[i]));
        }
        if(ans==1e18) cout<<(-1)<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}