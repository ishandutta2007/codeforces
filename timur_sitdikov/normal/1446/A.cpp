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

vi ans, ans1;

void solve(){
	int n;
	ll W;
	ll sum = 0;
	scanf("%d%lld", &n, &W);
	ans.clear();
	ans1.clear();
	REP(i, 0, n) {
		int w;
		scanf("%d", &w);
		if (2ll * w >= W && w <= W) {
			ans1.clear();
			ans1.pb(i + 1);
		} else if (sum + w <= W) {
			sum += w;
			ans.pb(i + 1);
		}
		
	}
	if (SZ(ans1) == 1) {
		printf("1\n%d\n", ans1[0]);
		return;
	}
	if (!(sum * 2 >= W && sum <= W)) {
		//ans.clear();
		//ans.pb(-1);
		printf("-1\n");
		return;
	}
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d ", ans[i]);
	}
	putchar('\n');
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