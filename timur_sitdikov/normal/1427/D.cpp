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

vi v;

vector<vi> ans;
vi cur, tmp;

void solve(){
	int n;
	scanf("%d", &n);
	v.reserve(n);
	REP(i, 0, n) {
		scanf("%d", &v[i]);
		v[i]--;
	}
	int it = 0;
	while(1) {
		/*REP(i, 0, n) {
			printf("%d ", v[i]);
		}
		putchar('\n');
		
		it++;
		if (it > 100) {
			break;
		}*/
		
		int l = -1, r = -1;
		REP(i, 0, n) {
			REP(j, i + 1, n) {
				if (v[i] == v[j] + 1) {
					l = i;
					r = j;
				}
			}
		}
		if (l == -1) {
			break;
		}
		cur.clear();
		if (l > 0) {
			cur.pb(l);
		}
		int len = 0;
		for(; v[l + len] == v[l] + len; len++);
		cur.pb(len);
		cur.pb(r - l - len + 1);
		if (r < n - 1) {
			cur.pb(n - 1 - r);
		}
		ans.pb(cur);
		tmp.clear();
		int last = n;
		for(int i = SZ(cur) - 1; i >= 0; i--) {
			REP(j, last - cur[i], last) {
				tmp.pb(v[j]);
			}
			last = last - cur[i];
		}
		
		v = tmp;
	}
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d", SZ(ans[i]));
		REP(j, 0, SZ(ans[i])) {
			printf(" %d", ans[i][j]);
		}
		putchar('\n');
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