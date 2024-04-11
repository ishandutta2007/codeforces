#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

const int N=1e5+100,M=2e5+100;

int u[M],v[M];

int lead[N];
int dsu(int x)
{
    return lead[x]==x?x:lead[x]=dsu(lead[x]);
}
bool un(int x,int y)
{
    x=dsu(x);
    y=dsu(y);
    if(x==y)
        return false;
    if(rand()&1)
        lead[x]=y;
    else
        lead[y]=x;
    return true;
}

vector<int> g[N];

const int l=18;
int tin[N], tout[N];
int timer=0;
int up[N][l+1];
int depth[N];

void dfs (int v, int p = 1,int d=0) {
	tin[v] = ++timer;
	depth[v]=d;
	up[v][0] = p;
	for (int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			dfs (to, v,d+1);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

int f(int u,int v)
{
    int diff=depth[v]-depth[u]-1;
    for(int i=0;i<=l;i++)
        if((diff>>i)&1)
            v=up[v][i];
    return v;
}

int add[N];

bool ans[N];

void solve(int v,int p,int cnt)
{
    cnt+=add[v];
    if(!cnt)
        ans[v]=true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			solve (to, v,cnt);
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i];
    for(int i=1;i<=n;i++)
        lead[i]=i;
    for(int i=1;i<=m;i++)
        if(un(u[i],v[i]))
            g[u[i]].push_back(v[i]),
            g[v[i]].push_back(u[i]);
    dfs(1);
    for(int i=1;i<=m;i++)
    {
        int x=lca(u[i],v[i]);
        if(x==u[i])
            add[f(u[i],v[i])]++,add[v[i]]--;
        else if(x==v[i])
            add[f(v[i],u[i])]++,add[u[i]]--;
        else
            add[1]++,add[u[i]]--,add[v[i]]--;
    }
    solve(1,0,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i];
}