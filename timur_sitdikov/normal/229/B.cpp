#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
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

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 1e6;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 1e5 + 5;

vector<pii> g[MAXN];

int d[MAXN];

set<pii> st;
set<int> bad[MAXN];
set<int> good[MAXN];

void dijkstra(int n) {
	REPN(i, 1, n) {
		d[i] = INF;
	}
	d[1] = 0;
	REPN(i, 1, n) {
		st.insert({d[i], i});
	}
	while(!st.empty()) {
		int s = st.begin()->_2;
		st.erase(st.begin());
		int dd = d[s];
		if (bad[s].count(dd)) {
			dd = *good[s].lower_bound(dd);
		}
		REP(i, 0, SZ(g[s])) {
			int to = g[s][i]._1, dis = dd + g[s][i]._2;
			if (d[to] > dis) {
				st.erase({d[to], to});
				d[to] = dis;
				st.insert({d[to], to});
			}
		}
	}
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	REPN(i, 1, n) {
		int k, t;
		scanf("%d", &k);
		REP(j, 0, k) {
			scanf("%d", &t);
			bad[i].insert(t);
			good[i].insert(t + 1);
		}
		FA(it, bad[i]) {
			good[i].erase(*it);
		}
	}
	dijkstra(n);
	if (d[n] == INF) {
		d[n] = -1;
	}
	printf("%d\n", d[n]);
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