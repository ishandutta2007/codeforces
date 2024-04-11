#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

set<int> g[N];

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        g[i].clear();
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    set<pii> mn;
    for(int i=1;i<=n;i++)
        mn.insert({g[i].size(),i});
    set<pii> bad;
    while(!mn.empty())
    {
        int v=mn.begin()->y;
        auto&oth=g[v];
        if(oth.size()>=k)
            break;
        if(oth.size()==k-1)
        {
            bool ok=true;
            int cnt=oth.size()*oth.size();
            for(auto[x,y]:bad)
            {
                if(!cnt--)
                    break;
                if(oth.count(x)&&oth.count(y))
                {
                    ok=false;
                    break;
                }
            }
            for(int x:oth)
            {
                if(!ok)
                    break;
                for(int y:oth)
                    if(x!=y&&!g[x].count(y))
                    {
                        bad.insert({x,y});
                        ok=false;
                        break;
                    }
            }
            if(ok)
            {
                cout<<2<<"\n";
                cout<<v<<" ";
                for(int u:oth)
                    cout<<u<<" ";
                cout<<"\n";
                return;
            }
        }
        mn.erase(mn.begin());
        for(int u:oth)
            mn.erase({g[u].size(),u}),
            g[u].erase(v),
            mn.insert({g[u].size(),u});
        oth.clear();
    }
    if(mn.empty())
        cout<<"-1\n";
    else
    {
        cout<<1<<" "<<mn.size()<<"\n";
        for(auto[s,v]:mn)
            cout<<v<<" ";
        cout<<"\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}