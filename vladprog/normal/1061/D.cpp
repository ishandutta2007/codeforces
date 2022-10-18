#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e5+100;
const int MOD=1e9+7;

pair<int,int> lr[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++)
        cin>>lr[i].first>>lr[i].second;
    sort(lr,lr+n);
    multiset<int> teleki;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int l=lr[i].first;
        int r=lr[i].second;
        auto it=teleki.lower_bound(l);
        if(it==teleki.begin())
            ans=(ans+x+y*(r-l))%MOD,teleki.insert(r);
        else
        {
            it--;
            int res1=x+y*(r-l);
            int res2=(r-*it)*y;
            if(res1<=res2)
                ans=(ans+res1)%MOD,teleki.insert(r);
            else
                ans=(ans+res2)%MOD,
                teleki.erase(it),
                teleki.insert(r);
        }
    }
    cout<<ans;
}