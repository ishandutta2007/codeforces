#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxv = maxn << 1;
const int logv = 19;

int n, m, q, col;
int a[maxv];
vector<int> g[maxv];
multiset<int> ms[maxv];

namespace Tarjan{
	int tot = 0, clk = 0, top = 0;
	int head[maxn], low[maxn], dfn[maxn], cut[maxn];
	int to[maxn << 1], vis[maxn << 1], nxt[maxn << 1], stk[maxn << 1];
	
	inline void init(){
		col = n;
		memset(head, -1, sizeof(head));
		memset(dfn, -1, sizeof(dfn));
		return;
	}
	
	inline void add(int u, int v){
		to[tot] = v;
		nxt[tot] = head[u];
		head[u] = tot++;
		return;
	}
	
	inline void addEdge(int u, int v){
		add(u, v);
		add(v, u);
		return;
	}
	
	inline void tarjan(int u, int p){
		low[u] = dfn[u] = clk++;
		int son = 0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v = to[i];
			if(v == p || vis[i])
				continue;
			++son;
			vis[i] = vis[i ^ 1] = 1;
			stk[++top] = i;
			if(!~dfn[v]){
				tarjan(v, u);
				low[u] = min(low[u], low[v]);
				cut[u] = true;
				if(low[v] >= dfn[u]){
					for(int j = stk[top--]; ; j = stk[top--]){
						g[to[j]].PB(col);
						g[to[j ^ 1]].PB(col);
						g[col].PB(to[j]);
						g[col].PB(to[j ^ 1]);
						if(j == i)
							break;
					}
					++col;
				}
			}
			else if(v != p)
				low[u] = min(low[u], dfn[v]);
		}
		if(u == p && son < 2)
			cut[u] = false;
		return;
	}
	
	inline void work(){
		FOR(u, 0, n) if(!~dfn[u])
			tarjan(u, u);
		FOR(u, 0, col){
			sort(g[u].begin(), g[u].end());
			g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
		}
		return;
	}
}

namespace HLD{
	int cnt, clk;
	int mx[maxv], sz[maxv], blk[maxv], pos[maxv], que[maxv], dep[maxv];
	int head[maxv], len[maxv];
	int fa[maxv][logv];

	class SegmentTree{
	private:
		static const int siz = 262144;
		int dat[siz << 1];
	public:
		inline int size(){ return siz; }
		inline void build(int x, int l, int r){
			if(l == r){
				if(l < col)
					dat[x] = a[que[l]];
				else
					dat[x] = INF;
				return;
			}
			int md = l + r >> 1;
			build(x << 1, l, md);
			build(x << 1 | 1, md + 1, r);
			dat[x] = min(dat[x << 1], dat[x << 1 | 1]);
			return;
		}
		
		inline int query(int x, int l, int r, int s, int t){
			if(l >= s && r <= t){
				return dat[x];
			}
			int md = l + r >> 1;
			if(s > md)
				return query(x << 1 | 1, md + 1, r, s, t);
			if(t <= md)
				return query(x << 1, l, md, s, t);
			return min(query(x << 1, l, md, s, t), query(x << 1 | 1, md + 1, r, s, t));
		}
		
		inline void update(int x, int l, int r, int y, int k){
			if(l == r){
				dat[x] = k;
				return;
			}
			int md = l + r >> 1;
			if(y <= md)
				update(x << 1, l, md, y, k);
			else
				update(x << 1 | 1, md + 1, r, y, k);
			dat[x] = min(dat[x << 1], dat[x << 1 | 1]);
			return;
		}
	}seg;
	
	inline void precalc(int u, int p){
		mx[u] = -1;
		fa[u][0] = p;
		if(~p)
			dep[u] = dep[p] + 1;
		FOR(i, 0, g[u].size()){
			int v = g[u][i];
			if(v == p)
				continue;
			precalc(v, u);
			sz[u] += sz[v];
			if(!~mx[u] || sz[v] > sz[mx[u]])
				mx[u] = v;
		}
		++sz[u];
		return;
	}

	inline void hld(int u, int p){
		if(!~head[cnt])
			head[cnt] = u;
		blk[u] = cnt;
		pos[u] = clk;
		que[clk++] = u;
		if(~mx[u])
			hld(mx[u], u);
		FOR(i, 0, g[u].size()){
			int v = g[u][i];
			if(v == p || v == mx[u])
				continue;
			++cnt;
			hld(v, u);
		}
		return;
	}

	inline void init(){
		memset(head, -1, sizeof(head));
		precalc(0, -1);
		hld(0, -1);
		FOR(u, 0, col){
			if(u < n){
				FOR(i, 0, g[u].size()){
					int v = g[u][i];
					if(v >= n && dep[v] < dep[u])
						ms[v].insert(a[u]);
				}
			}
			else{
				a[u] = *ms[u].begin();
			}
		}
		FOR(i, 1, logv){
			FOR(u, 0, col)
				fa[u][i] = (~fa[u][i - 1] ? fa[fa[u][i - 1]][i - 1] : -1);
		}
		seg.build(1, 0, seg.size() - 1);
		return;
	}
	
	inline int lca(int u, int v){
		if(dep[u] < dep[v])
			swap(u, v);
		for(int i = logv - 1; i >= 0; --i) if((dep[u] - dep[v]) >> i & 1)
			u = fa[u][i];
		if(u == v)
			return u;
		for(int i = logv - 1; i >= 0; --i) if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
		return fa[u][0];
	}
	
	inline void update(int u){
		seg.update(1, 0, seg.size() - 1, pos[u], a[u]);
		return;
	}

	inline int climb(int u, int r){
		int ret = INF;
		for(; blk[u] != blk[r]; u = fa[head[blk[u]]][0])
			ret = min(ret, seg.query(1, 0, seg.size() - 1, pos[head[blk[u]]], pos[u]));
		ret = min(ret, seg.query(1, 0, seg.size() - 1, pos[r], pos[u]));
		return ret;
	}
	
	inline int query(int u, int v){
		int r = lca(u, v), ret = INF;
		if(~fa[r][0] && r >= n)
			ret = a[fa[r][0]];
		ret = min(ret, climb(u, r));
		ret = min(ret, climb(v, r));
		return ret;
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 0, n)
		scanf("%d", a + i);
		
	Tarjan::init();
	FOR(i, 0, m){
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		Tarjan::addEdge(u, v);
	}
	Tarjan::work();
	HLD::init();
	
	FOR(i, 0, q){
		char buf[10];
		int x, y;
		scanf("%s%d%d", buf, &x, &y);
		if(buf[0] == 'C'){
			--x;
			int v = HLD::fa[x][0];
			if(v >= n){
				ms[v].erase(a[x]);
				ms[v].insert(y);
				a[v] = *ms[v].begin();
				HLD::update(v);
			}
			a[x] = y;
			HLD::update(x);
		}
		else{
			--x; --y;
			printf("%d\n", HLD::query(x, y));
		}
	}
	return 0;
}