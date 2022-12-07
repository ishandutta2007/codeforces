#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 2e5;
const int M = 3e5;
const int Q = 5e5;

typedef pair<int,int> pii;

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

//////////////////////////////////// kruskal

vector<int> E[2*N+5];
pii I[Q+M+5];
int n,m,q,cnt;
int p[N+5],l[2*N+5],r[2*N+5],loc[Q+M+5];
int lf[N+5],leafn;

struct SegTree{
	int maxn[4*N+5],pos[4*N+5];
	void pushup(int u){
		int lc = glc(u),rc = grc(u);
		if(maxn[lc] > maxn[rc])maxn[u] = maxn[lc],pos[u] = pos[lc];
		else maxn[u] = maxn[rc],pos[u] = pos[rc];
	}
	void build(int u,int l,int r){
		if(l == r){maxn[u] = p[lf[l]],pos[u] = l;return;}
		int m = (l + r) >> 1;
		build(glc(u),l,m);
		build(grc(u),m + 1,r);
		pushup(u);
	}
	void ud(int u,int l,int r,int p){
		if(l == r){maxn[u] = 0;return;}
		int m = (l + r) >> 1;
		if(p <= m)ud(glc(u),l,m,p);
		else ud(grc(u),m + 1,r,p);
		pushup(u);
	}
	pii query(int u,int l,int r,int ql,int qr){ // first = maxn,second = pos;
		if(l == ql && r == qr)return make_pair(maxn[u],pos[u]);
		int m = (l + r) >> 1;
		if(qr <= m)return query(glc(u),l,m,ql,qr);
		else if(ql > m)return query(grc(u),m + 1,r,ql,qr);
		else{
			pii p1 = query(glc(u),l,m,ql,m);
			pii p2 = query(grc(u),m + 1,r,m + 1,qr);
			if(p1.first > p2.first)return p1;
			else return p2;
		}
	}
	void update(int l,int r){
		pii p = query(1,1,n,l,r);
		ud(1,1,n,p.second);
		write(p.first),putchar('\n');
	}
}T;

void dfs(int u){
	if(E[u].size() == 0){
		leafn++;
		lf[leafn] = u;
		l[u] = r[u] = leafn;
		return;
	}
	l[u] = n,r[u] = 1;
	for(rg int i = 0;i < E[u].size();i++){
		int v = E[u][i];
		dfs(v);
		l[u] = min(l[u],l[v]);
		r[u] = max(r[u],r[v]);
	}
}

////////////////////////////////////////// DSU

struct DSU{
	int fa[N+5];
	void init(){
		for(rg int i = 1;i <= n;i++)fa[i] = i;
	} 
	int getfa(int x){
		int y = fa[x];
		if(fa[y] == y)return y;
		return fa[x] = getfa(y);
	}
	In void con(int x,int y){
		int fx = getfa(x),fy = getfa(y);
		if(fx == fy)return;
		else{
			cnt++;
			fa[cnt] = cnt;
			fa[fx] = fa[fy] = cnt;
			E[cnt].push_back(fx);
			E[cnt].push_back(fy);
		}
	}
}D;
void solve(){
	for(rg int i = 1;i <= cnt;i++)if(D.getfa(i) == i)dfs(i);
	T.build(1,1,n);
	for(rg int i = 1;i <= q;i++){
		if(I[i].first == 2)continue;
		else{
			int p = loc[i];
			T.update(l[p],r[p]);
		}
	}
}	

//////////////////////////////////// prepro

pii e[M+5];
bool vis[M+5];

void prepro(){
	cnt = n;D.init();
	for(rg int i = q;i >= 1;i--)if(I[i].first == 2){
		int id = I[i].second,x = e[id].first,y = e[id].second;
		D.con(x,y);
	}
	else loc[i] = D.getfa(I[i].second);
}

int main(){
//	freopen("CF1416D.in","r",stdin);
//	freopen("CF1416D.out","w",stdout);
	n = read(),m = read(),q = read();
	for(rg int i = 1;i <= n;i++)p[i] = read();
	for(rg int i = 1;i <= m;i++)e[i].first = read(),e[i].second = read();
	for(rg int i = 1;i <= q;i++){
		I[i].first = read(),I[i].second = read();
		if(I[i].first == 2)vis[I[i].second] = 1;
	}
	for(rg int i = 1;i <= m;i++)if(!vis[i])I[++q] = make_pair(2,i);
	prepro();
	solve();
	return 0;
}