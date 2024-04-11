#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int l[N],r[N];
vector<int> g[N];
int dpl[N],dpr[N];

void dfs(int v,int p)
{
    dpl[v]=dpr[v]=0;
    for(int to:g[v])
        if(to!=p)
        {
            dfs(to,v);
            dpl[v]+=max(dpl[to]+abs(l[v]-l[to]),
                        dpr[to]+abs(l[v]-r[to]));
            dpr[v]+=max(dpl[to]+abs(r[v]-l[to]),
                        dpr[to]+abs(r[v]-r[to]));
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
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>l[i]>>r[i],
            g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        cout<<max(dpl[1],dpr[1])<<"\n";
    }
}