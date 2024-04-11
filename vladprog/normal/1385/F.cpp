#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

set<int> g[N];
int deg[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            g[i].clear(),
            deg[i]=0;
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].insert(y);
            g[y].insert(x);
        }
        set<pii,greater<pii>> ver;
        for(int i=1;i<=n;i++)
            ver.insert({deg[i],i});
        #define to(v) (*g[v].begin())
        #define del(v) \
            ver.erase({deg[to(v)],to(v)}), \
            g[to(v)].erase(v), \
            deg[to(v)]++, \
            ver.insert({deg[to(v)],to(v)}), \
            g[v].clear()
        for(int i=1;i<=n;i++)
            if(g[i].size()==1&&!deg[i])
                del(i);
        int ans=0;
        while(!ver.empty())
        {
            int v=ver.begin()->y;
            if(deg[v]<k)
                break;
            ver.erase(ver.begin());
//            cout<<v<<" -> "<<deg[v]<<" ";
            ans+=deg[v]/k;
            deg[v]%=k;
            if(g[v].size()==1&&!deg[v])
//                cout<<"del\n",
                del(v);
            else
//                cout<<"ins\n",
                ver.insert({deg[v],v});
        }
        cout<<ans<<"\n";
    }
}