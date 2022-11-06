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

const int MAXN = 3e5 + 5;

int tmp[MAXN];

vector<vi> vv[2];

vi tmp0, tmp1;

void solve(){
	int n;
	scanf("%d", &n);
	vv[0].resize(1);
	vv[0][0].resize(n);
	REP(i, 0, n) {
		scanf("%d", &vv[0][0][i]);
	}
	ll ans_inv = 0;
	int ans_x = 0;
	for(int k = 29; k >= 0; k--) {
		ll cur0 = 0, cur1 = 0;
		int ind = (k + 1) & 1;
		REP(i, 0, SZ(vv[ind])) {
			int cnt0 = 0, cnt1 = 0;
			REP(j, 0, SZ(vv[ind][i])) {
				if (vv[ind][i][j] & (1 << k)) {
					cur1 += cnt0;
					cnt1++;
				} else {
					cur0 += cnt1;
					cnt0++;
				}
			}
		}
		if (cur1 < cur0) {
			ans_inv += cur1;
			ans_x ^= (1 << k);
			REP(i, 0, SZ(vv[ind])) {
				REP(j, 0, SZ(vv[ind][i])) {
					vv[ind][i][j] ^= (1 << k);
				}
			}
		} else {
			ans_inv += cur0;
		}
		vv[ind ^ 1].clear();
		REP(i, 0, SZ(vv[ind])) {
			tmp0.clear();
			tmp1.clear();
			REP(j, 0, SZ(vv[ind][i])) {
				if (vv[ind][i][j] & (1 << k)) {
					tmp1.pb(vv[ind][i][j]);
				} else {
					tmp0.pb(vv[ind][i][j]);
				}
			}
			if (!tmp0.empty()) {
				vv[ind ^ 1].pb(tmp0);
			}
			if (!tmp1.empty()) {
				vv[ind ^ 1].pb(tmp1);
			}
		}
	}
	printf("%lld %d\n", ans_inv,ans_x);
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