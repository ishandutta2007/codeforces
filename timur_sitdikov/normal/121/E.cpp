#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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

const int MAXN = 1e5 + 5, MAXD = 1e4 + 5;
const int LEN = 1500;

vi goods;
int is_good[MAXN];

void gen() {
	REPN(i, 1, 4) {
		REP(j, 0, 1 << i) {
			int v = 0;
			int st10 = 1;
			REP(k, 0, i) {
				// v *= 10;
				if (j & (1 << k)) {
					v += 7 * st10;
				} else {
					v += 4 * st10;
				}
				st10 *= 10;
			}
			goods.pb(v);
			is_good[v] = 1;
			//printf("%d\n", v);
		}
	}
}

struct query {
	int t, l, r, v;
} qq[MAXN];

int v[MAXN];

int ans[MAXN];

int cnt[MAXD];

void process(int l, int r, int q) {
	REP(i, 0, MAXD) {
		cnt[i] = 0;
	}
	REPN(i, l, r) {
		cnt[v[i]]++;
	}
	int add = 0;
	REPN(i, 1, q) {
		if (qq[i].t == 2) {
			if (qq[i].l > r || qq[i].r < l) {
				continue;
			}
			if (qq[i].l > l || qq[i].r < r) {
				REPN(j, max(qq[i].l, l), min(qq[i].r, r)) {
					if (is_good[v[j] + add]) {
						ans[i]++;
					}
				}
			} else {
				REP(j, 0, SZ(goods)) {
					if (goods[j] >= add) {
						ans[i] += cnt[goods[j] - add];
					}
				}
			}
		} else {
			if (qq[i].l > r || qq[i].r < l) {
				continue;
			}
			if (qq[i].l > l || qq[i].r < r) {
				REPN(j, max(qq[i].l, l), min(qq[i].r, r)) {
					cnt[v[j]]--;
					v[j] += qq[i].v;
					cnt[v[j]]++;
				}
			} else {
				add += qq[i].v;
			}
		}
	}
}

void solve(){
	gen();
	int n, q;
	char s[10];
	scanf("%d%d", &n, &q);
	REP(i, 0, n) {
		scanf("%d", &v[i]);
	}
	REPN(i, 1, q) {
		scanf("%s", &s[0]); 
		if (s[0] == 'a') {
			qq[i].t = 1;
			scanf("%d%d%d", &qq[i].l, &qq[i].r, &qq[i].v);
		} else {
			qq[i].t = 2;
			scanf("%d%d", &qq[i].l, &qq[i].r);
		}
		qq[i].l--, qq[i].r--;
	}
	for(int j = 0; j < n; j += LEN) {
		int l = j, r = min(j + LEN - 1, n - 1);
		process(l, r, q);
	}
	REPN(i, 1, q) {
		if (qq[i].t == 2) {
			printf("%d\n", ans[i]);
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