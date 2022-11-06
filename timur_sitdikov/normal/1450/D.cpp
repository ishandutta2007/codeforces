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

const int MAXN = 3e5 + 5;

vi ind[MAXN];

char ans[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	ans[n] = 0;
	REP(i, 0, n) {
		ind[i].clear();
		ans[i] = '0';
	}
	REP(i, 0, n) {
		int a;
		scanf("%d", &a);
		a--;
		ind[a].pb(i);
	}
	ans[n - 1] = '1';
	REP(i, 0, n) {
		if (SZ(ind[i]) != 1) {
			ans[n - 1] = '0';
		}
	}
	int l = 0, r = n - 1;
	REP(i, 0, n - 1) {
		if (SZ(ind[i]) == 0) {
			break;
		}
		ans[i] = '1';
		if (SZ(ind[i]) != 1 || ind[i][0] != l && ind[i][0] != r) {
			break;
		}
		if (ind[i][0] == l) {
			l++;
		} else {
			r--;
		}
	}
	reverse(ans, ans + n);
	printf("%s\n", ans);
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