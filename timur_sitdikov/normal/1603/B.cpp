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

const int MAXN = 3e5 + 5;

bool check(int x, int y, int n) {
	if (n <= 0) {
		return false;
	}
	return n % x == y % n;
}

int get(int x, int y) {
	/*for(int i = a; i <= b; i++) {
		if (i % a == b % i) {
			printf("%d %d %d\n", a, b, i);
			return;
		}
	}
	printf("%d %d: *********************\n", a, b);*/
	if (check(x, y, x + y)) {
		return x + y;
	}
	if (check(x, y, x)) {
		return x;
	}
	if (check(x, y, (x + y) / 2)) {
		return (x + y) / 2;
	}
	if (check(x, y, x + (y % x) / 4)) {
		return x + (y % x) / 4;
	}
	if (check(x, y, y - x / 2 - (y % x) / 2)) {
		return y - x / 2 - (y % x) / 2;
	}
	printf("%d %d: *********************\n", x, y);
	return -1;
}



void solve(){
	/*REPN(i, 10, 20) {
		REPN(j, 2, 100) {
			if (i % 2 == 1 || j % 2 == 1) {
				continue;
			}
			get(i, j);
		}
	}*/
	int x, y;
	scanf("%d%d", &x, &y);
	int ans = get(x, y);
	printf("%d\n", ans);
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