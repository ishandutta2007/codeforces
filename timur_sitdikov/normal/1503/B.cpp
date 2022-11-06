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

int cnt[4];
vector<pii> pos[4];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			pos[(i + j) % 2 + 1].pb({i, j});
		}
	}
	REP(i, 0, n * n) {
		int a;
		scanf("%d", &a);
		if (!pos[1].empty() && a != 1) {
			printf("1 %d %d\n", pos[1].back()._1, pos[1].back()._2);
			pos[1].pop_back();
		} else if (!pos[2].empty() && a != 2) {
			printf("2 %d %d\n", pos[2].back()._1, pos[2].back()._2);
			pos[2].pop_back();
		} else if (!pos[1].empty()) {
			printf("3 %d %d\n", pos[1].back()._1, pos[1].back()._2);
			pos[1].pop_back();
		} else {
			printf("3 %d %d\n", pos[2].back()._1, pos[2].back()._2);
			pos[2].pop_back();
		}
		fflush(stdout);
	}
}

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}