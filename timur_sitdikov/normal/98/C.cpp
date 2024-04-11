#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef long double DOUBLE;
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

const int MAXN = 2e5 + 5;

DOUBLE calc(int a, int b, int m, DOUBLE t) {
	DOUBLE sq = sqrt(max((DOUBLE)0., m * m - t * t));
	DOUBLE val = a * sq + b * t - t * sq;
	//printf("%.12lf %.12lf\n", (double)t, (double)val);
	return val;
}

void solve(){
	int a, b, m;
	cin >> a >> b >> m;
	DOUBLE lim = min(min(a, b), m);
	if (a >= m || b >= m) {
		printf("%.12lf\n", (double)lim);
		return;
	}
	if (m * m >= 2 * (a + b) * (a + b)) {
		printf("My poor head =(\n");
		return;
	}
	DOUBLE l = 0., r = m;
	REP(it, 0, 500) {
		DOUBLE l1 = ((DOUBLE)2. * l + r) / (DOUBLE)3.;
		DOUBLE r1 = (l + (DOUBLE)2. * r) / (DOUBLE)3.;
		DOUBLE vl = calc(a, b, m, l1);
		DOUBLE vr = calc(a, b, m, r1);
		if (vl < vr) {
			r = r1;
		} else {
			l = l1;
		}
	}
	// printf("%.12lf\n", (DOUBLE)l);
	DOUBLE ans = calc(a, b, m, (l + r) / (DOUBLE)2.) / m;
	if (ans < EPS) {
		printf("My poor head =(\n");
		return;
	}
	printf("%.12lf\n", (double)ans);
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