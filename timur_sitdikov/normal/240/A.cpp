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
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 3e2 + 5;

int x[MAXN], mn[MAXN], mx[MAXN], cnt[MAXN];
int good[MAXN];
char name[MAXN][20];

int ans[MAXN];

void solve(){
	int m, k, n, a;
	scanf("%d%d", &m, &k);
	REP(i, 0, k) {
		scanf("%d", &a);
		good[a] = 1;
	}
	scanf("%d", &n);
	REP(i, 0, n) {
		int t, cnt0 = 0;
		scanf("%s%d", &name[i][0], &t);
		REP(j, 0, t) {
			scanf("%d", &a);
			cnt[i] += good[a];
			if (a == 0) {
				cnt0++;
			}
			mn[i] = t - min(t - cnt[i], m - k);
			mx[i] = min(cnt[i] + cnt0, k);
		}
	}
	REP(i, 0, n) {
		int mn_rest = 0, mx_rest = 0;
		REP(j, 0, n) {
			if (i == j) {
				continue;
			}
			mx_rest = max(mx_rest, mx[j]);
			mn_rest = max(mn_rest, mn[j]);
		}
		if (mx_rest <= mn[i]) {
			ans[i] = 0;
		} else if (mn_rest > mx[i]) {
			ans[i] = 1;
		} else {
			ans[i] = 2;
		}
	}
	REP(i, 0, n) {
		printf("%d\n", ans[i]);
	}
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}