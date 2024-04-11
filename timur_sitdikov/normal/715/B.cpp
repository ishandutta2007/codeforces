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

#define file "points"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

const int MAXE = 2e4 + 5, MAXV = 1e3 + 5;

struct edge{
	int s, to, ind;
	bool is_free;
	ll w;
	edge(){}	
	edge(int _s, int _to, ll _w, bool _is_free, int _ind){
		s = _s;
		to = _to;		
		w = _w;
		is_free = _is_free;
		ind =_ind;
	}
};

set<pair<ll, int> > min_dis;

struct graph {
	// count of vertices and edges
	int n, m;
	
	// Array of edges
	// e[i], e[i ^ 1] represent one edge in two directions
	edge ee[MAXE];
	
	// Incident edges for vertices	
	vi g[MAXV];
	
	// Add edge
	void add_edge(int a, int b, ll w, bool is_free, int edge_index){
		ee[2 * edge_index] = edge(a, b, w, is_free, edge_index);
		ee[2 * edge_index + 1] = edge(b, a, w, is_free, edge_index);
		g[a].pb(2 * edge_index);
		g[b].pb(2 * edge_index + 1);
	}
	
	ll dis[MAXV], dis2[MAXV];
	int prv_e[MAXV];
	
	void dijkstra(int s){
		REPN(i, 1, n){
			dis[i] = INF;
			prv_e[i] = -1;
		}
		dis[s] = 0;
		min_dis.clear();
		REPN(i, 1, n){
			min_dis.insert(mp(dis[i], i));
		}
		while(!min_dis.empty()){
			s = min_dis.begin()->second;
			min_dis.erase(min_dis.begin());
			REP(i, 0, SZ(g[s])){
				int ind = g[s][i];
				int to = ee[ind].to;
				if (dis[to] > dis[s] + ee[ind].w){
					min_dis.erase(mp(dis[to], to));
					dis[to] = dis[s] + ee[ind].w;
					min_dis.insert(mp(dis[to], to));
					prv_e[to] = ind;
				}
			}
		}
	}
	
	void dijkstra2(int s, ll dif){
		REPN(i, 1, n){
			dis2[i] = INF;
			prv_e[i] = -1;
		}
		dis2[s] = 0;
		min_dis.clear();
		REPN(i, 1, n){
			min_dis.insert(mp(dis2[i], i));
		}
		while(!min_dis.empty()){
			s = min_dis.begin()->second;
			min_dis.erase(min_dis.begin());
			REP(i, 0, SZ(g[s])){
				int ind = g[s][i];
				int to = ee[ind].to;
				
				ll len = dis2[s] + ee[ind].w;
				if (ee[ind].is_free){
					ll add = max(len, dis[to] + dif) - len;
					len += add;
					ee[ind].w += add;
					ee[ind ^ 1].w += add;
				}
				if (dis2[to] > len){
					min_dis.erase(mp(dis2[to], to));
					dis2[to] = len;
					min_dis.insert(mp(dis2[to], to));
					prv_e[to] = ind;
				}
			}
		}
	}
};

graph gr;

void solve(){
	int s, t;
	ll L;
	scanf("%d%d%lld%d%d", &gr.n, &gr.m, &L, &s, &t);
	s++;
	t++;
	int a, b, l;
	REP(i, 0, gr.m){
		scanf("%d%d%d", &a, &b, &l);
		a++;
		b++;
		gr.add_edge(a, b, (ll)l, (l == 0), i);
	}
	REP(i, 0, 2 * gr.m){
		if (gr.ee[i].is_free){
			gr.ee[i].w = 1;
		}
	}
	
	/*REPN(i, 1, gr.n){
		REP(j, 0, SZ(gr.g[i])){
			int ind = gr.g[i][j];
			printf("%d %d %lld %d\n", gr.ee[ind].s, gr.ee[ind].to, gr.ee[ind].w, (int)gr.ee[ind].is_free);
		}
	}
	
	exit(0);*/

	gr.dijkstra(s);
	if (gr.dis[t] > L){
		printf("NO\n");
		return;
	}

	gr.dijkstra2(s, L - gr.dis[t]);
	if (gr.dis2[t] < L){
		printf("NO\n");
		return;
	}
	
	printf("YES\n");
	for(int i = 0; i < 2 * gr.m; i += 2){
		printf("%d %d %lld\n", gr.ee[i].s - 1, gr.ee[i].to - 1, gr.ee[i].w);
	}	
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