#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 1e5+100;

typedef long long ll;
#define int ll

map<pair<int, int>, int> mp;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int n, x, y, u, v;
        cin>>n;
        mp.clear();
        for (int j=1; j<=n; j++)
        {
            cin>>x>>y>>u>>v;
            u-=x;
            v-=y;
            int g = abs(__gcd(u, v));
            u/=g;
            v/=g;
            mp[{u, v}]++;
        }
        int ans=0;
        for (auto pa:mp)
        {
            ans+=pa.se * mp[{-pa.fi.fi, -pa.fi.se}];
        }
        cout<<ans/2<<"\n";
    }

}