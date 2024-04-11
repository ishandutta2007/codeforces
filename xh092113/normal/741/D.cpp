#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 5e5;
const int M = 1 << 22;
const int inf = 0x3f3f3f3f;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int f[M+5],ans[N+5];
int mask[N+5];

struct edge{
	int next,des,ch;
}e[N+5];

int cnt;
int head[N+5];

In void addedge(int a,int b,char ch){
	cnt++;
	e[cnt].des = b;
	e[cnt].next = head[a];
	e[cnt].ch = ch - 'a';
	head[a] = cnt; 
}

int son[N+5],sz[N+5],dfn[N+5],D[N+5],dep[N+5];
int dn;

void prepro(int u,int msk){
	mask[u] = msk;
	dn++;
	D[dn] = u,dfn[u] = dn;
	sz[u] = 1;
	int maxn = 0;
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].des;
		dep[v] = dep[u] + 1;
		prepro(v,msk ^ (1<<e[i].ch));
		sz[u] += sz[v];
		if(sz[v] > maxn)maxn = sz[v],son[u] = v;
	}
//cout<<"u="<<u<<" mask="<<mask[u]<<" sz="<<sz[u]<<" son="<<son[u]<<" dfn="<<dfn[u]<<endl;
}		

In int query(int cur){
	int rt = f[cur];
	for(rg int i = 0;i < 22;i++)rt = max(rt,f[cur^(1<<i)]);	
	return rt;
}

void dfs(int u,int keep){
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].des;
		if(v == son[u])continue;
		dfs(v,0);
	}
	if(son[u])dfs(son[u],1);
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].des;
		if(v == son[u])continue;
//cout<<"u="<<u<<" v="<<v<<endl;
		for(rg int j = dfn[v];j <= dfn[v] + sz[v] - 1;j++){
			int cur = mask[D[j]];
			ans[u] = max(ans[u],query(cur) + dep[D[j]] - 2 * dep[u]);
//cout<<"D[j]="<<D[j]<<" u="<<u<<" ans="<<ans[u]<<endl;
		}
		for(rg int j = dfn[v];j < dfn[v] + sz[v];j++)f[mask[D[j]]] = max(f[mask[D[j]]],dep[D[j]]);
	}
//cout<<"dfs:u="<<u<<" ans="<<ans[u]<<endl;
//for(rg int i = 0;i < 4;i++)cout<<f[i]<<" ";cout<<endl;
	ans[u] = max(ans[u],query(mask[u]) - dep[u]);
	f[mask[u]] = max(f[mask[u]],dep[u]);
	for(rg int i = head[u];i;i = e[i].next)ans[u] = max(ans[u],ans[e[i].des]);
	if(!keep){
		for(rg int i = dfn[u];i <= dfn[u] + sz[u] - 1;i++)
			f[mask[D[i]]] = -inf;
	}
}

int main(){
//	freopen("CF741D.in","r",stdin);
//	freopen("CF741D.out","w",stdout);
	int n = read();
	for(rg int i = 0;i < (1 << 22);i++)f[i] = -inf;
	for(rg int i = 2;i <= n;i++){
		int f = read();
		char ch = getchar();
		addedge(f,i,ch);
	}
	prepro(1,0);
	dfs(1,1);
	for(rg int i = 1;i <= n;i++){
		write(ans[i]);
		putchar(i == n ? '\n' : ' ');
	}
	return 0;
}