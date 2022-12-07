#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;

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
}
using namespace IO;

vector<int>E[N+5];
int n,fa[N+5],son[N+5],sz[N+5],clr[N+5];
int num[N+5],maxn;
int Dn,dfn[N+5],D[N+5];
ll sum[N+5],ans[N+5];

In void insert(int c){
	sum[num[c]] -= c;
	num[c]++;
	sum[num[c]] += c;
	while(sum[maxn+1])maxn++;
}

In void remove(int c){
	sum[num[c]] -= c;
	num[c]--;
	sum[num[c]] += c;
	while(!sum[maxn])maxn--;
}

void prepro(int u,int f){
	Dn++;
	D[Dn] = u,dfn[u] = Dn;
	fa[u] = f;
	sz[u] = 1;
	for(rg int i = 0;i < E[u].size();i++){
		int v = E[u][i];
		if(v == f)continue;
		prepro(v,u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]])son[u] = v;
	}
}

void dfs(int u,bool keep){
	for(rg int i = 0;i < E[u].size();i++){
		int v = E[u][i];
		if(v == son[u] || v == fa[u])continue;
		dfs(v,0);
	}
	if(son[u])dfs(son[u],1);
	for(rg int i = 0;i < E[u].size();i++){
		int v = E[u][i];
		if(v == son[u] || v == fa[u])continue;
		for(rg int j = dfn[v];j <= dfn[v] + sz[v] - 1;j++)insert(clr[D[j]]);
	}
	insert(clr[u]);
	ans[u] = sum[maxn];
	if(!keep)for(rg int i = dfn[u];i <= dfn[u] + sz[u] - 1;i++)remove(clr[D[i]]);
}

int main(){
//	freopen("CF600E.in","r",stdin);
//	freopen("CF600E.out","w",stdout);

	n = read();
	for(rg int i = 1;i <= n;i++)clr[i] = read();;
	for(rg int i = 1;i < n;i++){
		int u = read(),v = read();
		E[u].push_back(v);
		E[v].push_back(u);
	}

	prepro(1,0);
	sum[0] = 1e10;
	dfs(1,1);
	for(rg int i = 1;i <= n;i++){
		write(ans[i]);
		putchar(i == n ? '\n' : ' ');
	}

	return 0;
}