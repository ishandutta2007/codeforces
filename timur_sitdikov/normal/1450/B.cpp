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
const ll MOD = 1e9 + 7;

const int MAXN = 3e2 + 5;

int g[MAXN][MAXN];

int x[MAXN], y[MAXN];

int n;

void solve(){
	int k;
	scanf("%d%d", &n, &k);
	REP(i, 0, n) {
		scanf("%d%d", &x[i], &y[i]);
	}
	REP(i, 0, n) {
		int fl = 0;
		REP(j, 0, n) {
			g[i][j] = ((abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k) ? 1 : 0);
			if (!g[i][j]) {
				fl = 1;
			}
		}
		if (!fl) {
			printf("1\n");
			return;
		}
	}
	printf("-1\n");
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}