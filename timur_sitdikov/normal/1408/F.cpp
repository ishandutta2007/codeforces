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

vector<vi> sets;
vi tmp;

vector<pii> ans;

void solve(){
	int n;
	scanf("%d", &n);
	int offset = 1;
	for(int i = 20; i >= 0; i--) {
		if (n & (1 << i)) {
			tmp.clear();
			REP(j, 0, 1 << i) {
				tmp.pb(offset + j);
			}
			sets.pb(tmp);
			REP(j, 0, i) {
				for(int k = 0; k < (1 << i); k += (1 << (j + 1))) {
					REP(l, 0, 1 << j) {
						int to = k + l + (1 << j);
						ans.pb(mp(offset + k + l, offset + to));
					}
				}
			}
			offset += (1 << i);
		}
	}
	while(SZ(sets) > 2) {
		tmp.clear();
		vi &last = sets[SZ(sets) - 1];
		vi &pre_last = sets[SZ(sets) - 2];
		if (SZ(last) == SZ(pre_last)) {
			REP(j, 0, SZ(last)) {
				pre_last.pb(last[j]);
				ans.pb(mp(pre_last[j], last[j]));
			}
			sets.pop_back();
		} else {
			int ind = SZ(sets[0]) - SZ(last);
			REP(j, 0, SZ(last)) {
				tmp.pb(sets[0][ind + j]);
				tmp.pb(last[j]);
				ans.pb(mp(sets[0][ind + j], last[j]));
			}
			REP(j, 0, SZ(last)) {
				sets[0].pop_back();
			}
			sets[SZ(sets) - 1] = tmp;
		}
	}
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d %d\n", ans[i]._1, ans[i]._2);
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