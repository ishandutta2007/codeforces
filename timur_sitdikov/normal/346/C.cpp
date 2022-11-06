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

const int MAXN = 1e6 + 5;

int max_div[MAXN];
int max_pos[MAXN];
int x[MAXN];
int ans[MAXN];

void solve(){
	int n, a, b;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &x[i]);
	}
	scanf("%d%d", &a, &b);
	sort(x, x + n);
	REPN(i, 0, a - b) {
		max_div[i] = 1;
	}
	REP(i, 0, n) {
		if (i && x[i] == x[i - 1]) {
			continue;
		}
		int l = (b + x[i] - 1) / x[i] * x[i];
		for(int j = l - b; j <= a - b; j += x[i]) {
			max_div[j] = x[i];
		}
	}
	REPN(i, 1, a - b) {
		ans[i] = INF;
	}
	REPN(i, 0, a - b) {
		if (i) {
			ans[i] = ans[i - 1] + 1;
			if (max_pos[ans[i] - 1] >= i) {
				ans[i]--;
			}
		}
		int nxt_val = ans[i] + 1;
		max_pos[nxt_val] = max(max_pos[nxt_val], i + 1);
		max_pos[nxt_val] = max(max_pos[nxt_val], i + max_div[i] - 1);
	}
	printf("%d\n", ans[a - b]);
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