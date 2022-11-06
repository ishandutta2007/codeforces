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

const int MAXN = 2e5 + 5;

pii pp[MAXN];

void solve(){
	int n, k;
	ll b;
	scanf("%d%d%lld", &n, &k, &b);
	REP(i, 0, n) {
		scanf("%d", &pp[i]._1);
		pp[i]._2 = i;
	}
	sort(pp, pp + n - 1);
	reverse(pp, pp + n - 1);
	ll sum = 0;
	REP(i, 0, k - 1) {
		sum += pp[i]._1;
	}
	int ans = n - 1;
	REP(i, k - 1, n - 1) {
		ll cur = sum + pp[i]._1;
		if (cur > b) {
			ans = min(ans, pp[i]._2);
		}
	}
	sum += pp[k - 1]._1;
	if (sum > b) 
	REP(i, 0, k - 1) {
		ans = min(ans, pp[i]._2);
	}
	printf("%d\n", ans + 1);
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