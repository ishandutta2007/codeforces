#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
int x1[59],Y1[59],x2[59],y2[59];
typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};
bool vis[10009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	vi x(2*m),y(2*m);
	rep(i,m){
		cin>>x[2*i]>>y[2*i]>>x[2*i+1]>>y[2*i+1];
		x1[i]=x[2*i],Y1[i]=y[2*i];
		x2[i]=x[2*i+1],y2[i]=y[2*i+1];
		x[2*i+1]++;
		y[2*i+1]++;
	}
	sort(all(x));
	sort(all(y));
	x.resize(distance(x.begin(),unique(all(x))));
	y.resize(distance(y.begin(),unique(all(y))));
	PushRelabel P(sz(x)+sz(y)+2);
	rep(i,m){
		int stx = lower_bound(all(x),x1[i])-x.begin();
		int sty = lower_bound(all(y),Y1[i])-y.begin();
		int enx = lower_bound(all(x),x2[i]+1)-x.begin();
		int eny = lower_bound(all(y),y2[i]+1)-y.begin();
		repA(j,stx,enx-1){
			repA(k,sty,eny-1){
				P.add_edge(j+1,1+sz(x)+k,1e9+7);
			}
		}
	}
	rep(i,sz(x)-1){
		P.add_edge(0,1+i,x[i+1]-x[i]);
	}
	rep(i,sz(y)-1){
		P.add_edge(1+sz(x)+i,1+sz(y)+sz(x),y[i+1]-y[i]);
	}
	cout<<P.maxflow(0,1+sz(x)+sz(y));
	return 0;
}