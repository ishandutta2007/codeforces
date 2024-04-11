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

#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 5e5 + 5;

pii ee[MAXN];
pii qq[MAXN];
int val[MAXN];
int del_ee[MAXN];

vi init_sets[MAXN];
pii set_deletion[MAXN];

vector<vi> sets;
vector<set<pii> > val_sets;
int set_ind[MAXN];

int par[MAXN];

int get_par(int v) {
	return par[v] == v ? v: par[v] = get_par(par[v]);
}

void solve(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	REPN(i, 1, n) {
		scanf("%d", &val[i]);
	}
	REPN(i, 1, m) {
		scanf("%d%d", &ee[i]._1, &ee[i]._2);
	}
	REPN(i, 1, q) {
		scanf("%d%d", &qq[i]._1, &qq[i]._2);
		if (qq[i]._1 == 2) {
			del_ee[qq[i]._2] = i;
		}
	}
	REPN(i, 1, n) {
		par[i] = i;
	}
	REPN(i, 1, m) {
		if (!del_ee[i]) {
			int a = ee[i]._1, b = ee[i]._2;
			a = get_par(a);
			b = get_par(b);
			par[a] = b;
		}
	}
	REPN(i, 1, n) {
		int a = get_par(i);
		init_sets[a].pb(i);
	}
	REPN(i, 1, n) {
		if (!init_sets[i].empty()) {
			REP(j, 0, SZ(init_sets[i])) {
				set_ind[init_sets[i][j]] = SZ(sets);
			}
			sets.pb(init_sets[i]);
			// init_sets[i].clear();
		}
	}
	for(int i = q; i >= 1; i--) {
		if (qq[i]._1 == 2) {
			int e = qq[i]._2;
			int a = ee[e]._1, b = ee[e]._2;
			a = get_par(a);
			b = get_par(b);
			if (a != b) {
				int set_a = set_ind[a];
				int set_b = set_ind[b];
				if (SZ(sets[set_a]) > SZ(sets[set_b])) {
					swap(a, b);
					swap(set_a, set_b);
				}
				set_deletion[i] = {set_b, set_a};
				par[a] = b;
				REP(j, 0, SZ(sets[set_a])) {
					int c = sets[set_a][j];
					set_ind[c] = set_b;
					sets[set_b].pb(c);
				}
			} else {
				set_deletion[i] = {0, 0};
			}
		}
	}
	
	val_sets.resize(SZ(sets));
	REPN(i, 1, n) {
		val_sets[set_ind[i]].insert({-val[i], i});
	}
	
	REPN(i, 1, q) {
		if (qq[i]._1 == 2) {
			if (set_deletion[i] != mp(0, 0)) {
				int set_a = set_deletion[i]._2;
				int set_b = set_deletion[i]._1;
				REP(j, 0, SZ(sets[set_a])) {
					int c = sets[set_a][j];
					set_ind[c] = set_a;
					if (val[c] > 0) {
						val_sets[set_b].erase({-val[c], c});
						val_sets[set_a].insert({-val[c], c});
					}
					sets[set_b].pop_back();
				}
			}
		} else {
			int ind = set_ind[qq[i]._2];
			if (val_sets[ind].empty()) {
				printf("0\n");
			} else {
				int a = -(val_sets[ind].begin()->_1);
				val[val_sets[ind].begin()->_2] = 0;
				val_sets[ind].erase(val_sets[ind].begin());
				printf("%d\n", a);
			}
		}
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