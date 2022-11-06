#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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

ll solve_1(ll n) {
	n = (n + 2) / 3;
	ll st4 = 1;
	for(; st4 < n; st4 *= 4) {
		n -= st4;
	}
	ll ans = st4 + n - 1;
	return ans;
}

ll arr4[4] = {0, 2, 3, 1};

ll solve_2(ll n) {
	n = (n + 1) / 3;
	ll st4 = 1;
	for(; st4 < n; st4 *= 4) {
		n -= st4;
	}
	n--;
	ll ans = 2 * st4;
	for(ll dig = 1; n; dig *= 4, n /= 4) {
		ans = ans + dig * arr4[n % 4];
	}
	return ans;
}

void solve(){
	ll n;
	scanf("%lld", &n);
	ll ans = 0ll;
	if (n % 3 == 1) {
		ans = solve_1(n);
	} else if(n % 3 == 2) {
		ans = solve_2(n);
	} else {
		ans = solve_1(n - 2) ^ solve_2(n - 1);
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
	/*REPN(i, 1, 100) {
		cout << 3 * i - 2 << " " << solve_1(3 * i - 2) << endl;
	}*/
	/*REPN(i, 1, 100) {
		cout << 3 * i - 1 << " " << solve_2(3 * i - 1) << endl;
	}
	return 0;*/
    cin >> t;
    while(t--){
        solve();    
    }
}