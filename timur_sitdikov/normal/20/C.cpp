#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "distance"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e12;

const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5, MAXE = 2e5 + 5;

struct edge{
	int s, to, w;
	edge(){}
	edge(int _s, int _to, int _w){
		s = _s, to = _to, w = _w;
	}
};

struct graph {
	// Number of vertices and edges
	int n, m;
	
	// Edges (ind, ind ^ 1 - the same edge in different directions)
	edge ee[MAXE];
	
	// Graph
	vi g[MAXN];
	
	// minimal distances
	ll dis[MAXN];
	
	// Set for dijkstra
	set<pair<ll, int> > st;
	
	// Parents
	int prv[MAXN];
	
	// Adding edge
	void add_edge(int a, int b, int w, int ee_ind){
		ee[2 * ee_ind] = edge(a, b, w);
		ee[2 * ee_ind + 1] = edge(b, a, w);
		g[a].pb(2 * ee_ind);
		g[b].pb(2 * ee_ind + 1);
	}
	
	void dijkstra(int s){
		// Init distances, prv
		REPN(i, 1, n){
			dis[i] = INF;
			prv[i] = 0;
		}
		dis[s] = 0;
		
		// Init set
		st.clear();
		REPN(i, 1, n){
			st.insert(mp(dis[i], i));
		}
		
		// Go
		while(!st.empty()){
			int s = st.begin()->second;
			st.erase(st.begin());
			REP(i, 0, SZ(g[s])){
				int ind = g[s][i];
				int to = ee[ind].to;
				if (dis[to] > dis[s] + ee[ind].w){
					st.erase(mp(dis[to], to));
					dis[to] = dis[s] + ee[ind].w;
					st.insert(mp(dis[to], to));
					prv[to] = s;
				}
			}
		}		
	}
	
	// Restores path from s to to using prv
	// Error if no path
	vi get_path(int s, int to){
		vi ans;
		for(int a = to; ; a = prv[a]){
			ans.pb(a);
			if (a == s){
				break;
			}
		}
		reverse(BE(ans));
		return ans;
	}
};

graph gg;

void solve(){
	int a, b, w, s, f;
	scanf("%d%d", &gg.n, &gg.m);
	REP(i, 0, gg.m){
		scanf("%d%d%d", &a, &b, &w);
		gg.add_edge(a, b, w, i);
	}
	
	s = 1, f = gg.n;
	
	gg.dijkstra(s);
	
	if (gg.dis[f] == INF){
		printf("-1\n");
		return;
	}
	//printf("%d\n", gg.dis[f]);
	
	vi ans = gg.get_path(s, f);
	REP(i, 0, SZ(ans)){
		printf("%d ", ans[i]);
	}
	putchar('\n');
	
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}