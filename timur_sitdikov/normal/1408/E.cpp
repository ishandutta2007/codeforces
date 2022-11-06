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

// vector<pair<int, ll> > g[MAXN];

pair<ll, pii> ee[MAXN];

int a[MAXN], b[MAXN];

int par[MAXN];

int get_par(int v) {
	return par[v] == v ? v : par[v] = get_par(par[v]);
}

void solve(){
	int m, n;
	scanf("%d%d", &m, &n);
	REP(i, 0, m) {
		scanf("%d", &a[i]);
	}
	REP(j, 0, n) {
		scanf("%d", &b[j]);
	}
	int top = 0;
	ll ans = 0;
	REP(i, 0, m) {
		int k;
		scanf("%d", &k);
		REP(j, 0, k) {
			int c;
			scanf("%d", &c);
			c--;
			ll w = a[i] + b[c];
			//ans += w;
			ee[top++] = mp(w, mp(i, m + c));
		}
	}
	sort(ee, ee + top);
	reverse(ee, ee + top);
	REP(i, 0, n + m) {
		par[i] = i;
	}
	REP(i, 0, top) {
		int x = ee[i]._2._1, y = ee[i]._2._2;
		x = get_par(x);
		y = get_par(y);
		if (x != y) {
			par[x] = y;
		} else {
			ans += ee[i]._1;
		}
	}
	printf("%lld\n", ans);
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