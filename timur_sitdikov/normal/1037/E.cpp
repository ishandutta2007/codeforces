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

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

set<int> g[MAXN];

set<pii> st;

pii edges[MAXN];

int snm_par[MAXN], snm_sz[MAXN];

int get_par(int v) {
	return (v == snm_par[v] ? v : snm_par[v] = get_par(snm_par[v]));
}

vi tmp;

vector<pair<int, pii> > sorted;

void delete_edge(int a, int b, int level) {
	if (g[a].find(b) != g[a].end()) {
		st.erase(mp(SZ(g[a]), a));
		st.erase(mp(SZ(g[b]), b));
		g[a].erase(b);
		g[b].erase(a);
		st.insert(mp(SZ(g[a]), a));
		st.insert(mp(SZ(g[b]), b));
		sorted.pb(mp(level, mp(a, b)));
	}
}

void solve(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	REP(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[i] = mp(a, b);
		g[a].insert(b);
		g[b].insert(a);
	}
	REPN(i, 1, n) {
		st.insert(mp(SZ(g[i]), i));
	}
	for(int i = m - 1; i >= 0; i--) {
		while (!st.empty()) {
			if (st.begin()->_1 >= k) {
				break;
			}
			int a = st.begin()->_2;
			tmp.clear();
			FA(it, g[a]) {
				tmp.pb(*it);
			}
			REP(j, 0, SZ(tmp)) {
				delete_edge(a, tmp[j], i + 1);
			}
			st.erase(mp(SZ(g[a]), a));
		}
		delete_edge(edges[i]._1, edges[i]._2, i);
	}
	
	REPN(i, 1, n) {
		snm_par[i] = i;
		snm_sz[i] = 1;
	}
	
	SORT(sorted);
	/*REP(i, 0, SZ(sorted)) {
		printf("# %d %d %d\n", sorted[i]._2._1, sorted[i]._2._2, sorted[i]._1);
	}*/
	
	int cur = 0;
	int ans = 0;
	REP(i, 0, m) {
		for(; cur < SZ(sorted) && sorted[cur]._1 <= i; cur++) {
			int a = sorted[cur]._2._1;
			int b = sorted[cur]._2._2;
			a = get_par(a);
			b = get_par(b);
			if (a != b) {
				//printf("%d %d %d\n", i, a, b);
				if (snm_sz[a] == 1) {
					ans++;
				}
				if (snm_sz[b] == 1) {
					ans++;
				}
				snm_sz[a] += snm_sz[b];
				snm_par[b] = a;
				//ans = max(ans, snm_sz[a]);
			}
		}
		printf("%d\n", ans);
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