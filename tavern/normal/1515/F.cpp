#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
#define y0 y2226700
#define y1 y2226701
#define y2 y2226702
typedef double lf;
typedef long double Lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 3e5 + 5;

class Edge{
public:
	ll w;
	int u, v, id;
	Edge(ll w_, int u_, int v_, int id_): w(w_), u(u_), v(v_), id(id_){}	

	inline bool operator < (const Edge &oth)const{ return MP(w, id) > MP(oth.w, oth.id); }
	inline bool operator > (const Edge &oth)const{ return MP(w, id) < MP(oth.w, oth.id); }
	inline Edge operator + (const ll &x)const{ return Edge(w + x, u, v, id); }
} ;

int n, m, x;
int fa[maxn];
ll a[maxn];
vector<Edge> S[maxn];
vector<int> ans;

inline int find(int x){ return (fa[x] == x ? x : (fa[x] = find(fa[x]))); }

inline int merge(int u, int v){
	if(S[u].size() < S[v].size())
		swap(u, v);
	FOR(i, 0, S[v].size())
		S[u].PB(S[v][i]);
	fa[v] = u;
	(a[u] += a[v]) -= x;
	for(; S[u].size() && find(S[u].back().u) == find(S[u].back().v); S[u].pop_back());
	return u;
}

int main(){
	scanf("%d%d%d", &n, &m, &x);
	
	FOR(i, 0, n)
		scanf("%lld", a + i), fa[i] = i;
	
	FOR(i, 0, m){
		int u, v; scanf("%d%d", &u, &v); --u, --v;
		S[u].PB(Edge(0, u, v, i));
		S[v].PB(Edge(0, v, u, i));
	}
	
	priority_queue<Edge, vector<Edge>, greater<Edge> > que;
	
	FOR(u, 0, n) if(S[u].size()){
		que.PH(S[u].back() + a[u]);
	}
	
	for(int i = 0; !que.empty() && i < n - 1; ){
		Edge e = que.top(); que.pop();
		//printf("e = (%lld %d %d %d)\n", e.w, e.u, e.v, e.id);
		e.u = find(e.u), e.v = find(e.v);
		//printf("u = %d v = %d a = %lld %lld\n", e.u, e.v, a[e.u], a[e.v]);
		if(e.w != a[e.u])
			continue;
		if(e.u == e.v)
			continue;
		if(a[e.u] + a[e.v] - x < 0)
			break;
		++i;
		ans.PB(e.id);
		int rt = merge(e.u, e.v);
		if(!S[rt].empty()){
			que.PH(S[rt].back() + a[rt]);
		}
	}
	
	if(ans.size() < n - 1){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	FOR(i, 0, ans.size())
		printf("%d\n", ans[i] + 1);
	return 0;
}