#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

vector<int> g[N],h[N];
int tin[N],tout[N],tim;

void dfsh(int v)
{
    tin[v]=++tim;
    for(int to:h[v])
        dfsh(to);
    tout[v]=++tim;
}

set<pii> s;
int ans;

void dfsg(int v)
{
    auto it=s.lower_bound({tin[v],0});
    if(it!=s.begin())
        it--;
    int u=(it==s.end()?0:it->y);
    if(tin[u]<=tin[v]&&tout[v]<=tout[u])
        s.erase(it);
    else
        u=0;
//    cout<<"in "<<v<<" : delete "<<u<<"\n";
    s.insert({tin[v],v});
    ans=max<int>(ans,s.size());
    for(int to:g[v])
        dfsg(to);
    s.erase({tin[v],v});
    if(u)
        s.insert({tin[u],u});
//    cout<<"out "<<v<<" : add "<<u<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        g[1].clear();
        for(int i=2;i<=n;i++)
        {
            int a;
            cin>>a;
            g[a].push_back(i);
            g[i].clear();
        }
        h[1].clear();
        for(int i=2;i<=n;i++)
        {
            int b;
            cin>>b;
            h[b].push_back(i);
            h[i].clear();
        }
        tim=0;
        dfsh(1);
        s.clear();
        ans=0;
        dfsg(1);
        cout<<ans<<"\n";
    }
}