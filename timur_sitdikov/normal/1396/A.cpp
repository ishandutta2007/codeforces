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

ll v[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%lld", &v[i]);
	}
	if (n == 1) {
		printf("1 1\n%lld\n1 1\n0\n1 1\n0\n", -v[0]);
		return;
	}
	printf("1 %d\n", n - 1);
	REP(i, 0, n - 1) {
		ll add = (ll)(n - 1) * v[i];
		printf("%lld ", add);
		v[i] += add;
	}
	putchar('\n');
	printf("%d %d\n%lld\n", n, n, -v[n - 1]);
	v[n - 1] = 0;
	printf("1 %d\n", n);
	REP(i, 0, n) {
		printf("%lld ", -v[i]);
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
    //cin >> t;
    while(t--){
        solve();    
    }
}