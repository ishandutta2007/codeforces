#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;
const ll inf = 0x3f3f3f3f;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

//// prepro

int n,m;
int p[N+5];
int Dn,D[N+5],dfn[N+5];
int fa[N+5][20],dep[N+5];
vector<int> e[N+5];
vector<int> E[N+5];
vector<int> vc;

void prepro(int u,int ff){
	fa[u][0] = ff;
	dep[u] = dep[ff] + 1;
	D[++Dn] = u;dfn[u] = Dn;
	for(rg int i = 0;i < e[u].size();i++)if(e[u][i] != ff)prepro(e[u][i],u);
}
In int getlca(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	for(rg int i = 19;i >= 0;i--)if(dep[u] - (1 << i) >= dep[v])u = fa[u][i];
	if(u == v)return u;
	for(rg int i = 19;i >= 0;i--)if(fa[u][i] != fa[v][i])u = fa[u][i],v = fa[v][i];
	return fa[u][0];
}

//// solve

ll f[N+5][2];
int st[N+5],top;
bool imp[N+5];

In bool cmp(int x,int y){return dfn[x] < dfn[y];}
void addedge(int ff,int u){
	E[ff].push_back(u);
	vc.push_back(ff);
}
void dfs(int u){
	if(imp[u]){
		f[u][0] = inf;
		f[u][1] = 0;
		for(rg int i = 0;i < E[u].size();i++){
			int v = E[u][i];
			dfs(v);
			ll f0 = f[v][0],f1 = f[v][1];
			if(dep[u] + 1 < dep[v])f0 = min(f0,f1 + 1);
			f[u][1] += f0;
		}
	}
	else{
		ll case1 = 1,case2 = 0,minn = inf;
		f[u][1] = f[u][0] = 0;
		for(rg int i = 0;i < E[u].size();i++){
			int v = E[u][i];
			dfs(v);
			ll f0 = f[v][0],f1 = f[v][1];
			if(dep[u] + 1 < dep[v])f0 = min(f0,f1 + 1);
			case1 += min(f0,f1);
			case2 += f0;
			f[u][1] += f0;
			minn = min(minn,f1 - f0);
		}
		f[u][0] = min(case1,case2);
		f[u][1] += minn;
	}
}
void solve(){
	vc.resize(0);
	sort(p + 1,p + m + 1,cmp);
	for(rg int i = 1;i <= m;i++)imp[p[i]] = 1;
	st[top=1] = 1;
	for(rg int i = 1;i <= m;i++){
		int u = p[i];if(u == 1)continue;
		int lca = getlca(u,st[top]);
		if(lca == st[top])st[++top] = u;
		else{
			while(dep[st[top-1]] > dep[lca]){
				addedge(st[top-1],st[top]);
				top--;
			}
			if(st[top-1] == lca){
				addedge(st[top-1],st[top]);
				st[top] = u;
			}
			else{
				addedge(lca,st[top]);
				st[top] = lca;
				st[++top] = u;
			}
		}
	}
	for(rg int i = 1;i < top;i++)addedge(st[i],st[i+1]);
	dfs(1);
	ll ans = min(f[1][0],f[1][1]);
	if(ans >= inf)puts("-1");
	else write(ans),putchar('\n');
	for(rg int i = 1;i <= m;i++)imp[p[i]] = 0;
	for(rg int i = 0;i < vc.size();i++)E[vc[i]].resize(0);
}

int main(){
//	freopen("CF613D.in","r",stdin);
//	freopen("CF613D.out","w",stdout);
	n = read();
	for(rg int i = 1;i < n;i++){
		int u = read(),v = read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	prepro(1,0);
	for(rg int i = 1;i <= 19;i++)
		for(rg int u = 1;u <= n;u++)fa[u][i] = fa[fa[u][i-1]][i-1];
	int T = read();
	while(T--){
		m = read();
		for(rg int i = 1;i <= m;i++)p[i] = read();
		solve();
	}	
	return 0;
}