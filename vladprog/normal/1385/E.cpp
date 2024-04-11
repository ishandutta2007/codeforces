#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

vector<int> g[N],gr[N];
pii e[N];
bool used[N];
vector<int> order,component;
int val[N];

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            g[i].clear(),
            gr[i].clear();
        order.clear();
        for(int i=1;i<=m;i++)
        {
            int tp;
            cin>>tp>>e[i].x>>e[i].y;
            if(tp)
                g[e[i].x].push_back(e[i].y),
                gr[e[i].y].push_back(e[i].x);
        }
        memset(used+1,0,n);
        for(int i=1;i<=n;i++)
            if(!used[i])
                dfs1(i);
        memset(used+1,0,n);
        memset(val+1,0,n*sizeof(int));
        bool bad=false;
        int tim=0;
        for(int i=0;i<n;i++)
        {
            int v=order[n-1-i];
            if(!used[v])
            {
                dfs2(v);
                if(component.size()>1)
                    bad=true;
                val[v]=++tim;
                component.clear();
            }
        }
        if(bad)
        {
            cout<<"NO\n";
            continue;
        }
        for(int i=1;i<=n;i++)
            if(!val[i])
                val[i]=++tim;
        cout<<"YES\n";
        for(int i=1;i<=m;i++)
            if(val[e[i].x]<val[e[i].y])
                cout<<e[i].x<<" "<<e[i].y<<"\n";
            else
                cout<<e[i].y<<" "<<e[i].x<<"\n";
    }
}