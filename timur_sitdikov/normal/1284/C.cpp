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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;

ll MOD;

const int MAXF = 5e5 + 5;

ll f[MAXF], f_inv[MAXF];

ll pow_mod(ll a, ll st) {
	ll ans = 1ll;
	for(; st; st >>= 1ll) {
		if (st & 1) {
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

ll get_inv(ll v) {
	return pow_mod(v, MOD - 2);
}

void gen_f() {
	f[0] = 1;
	REP(i, 1, MAXF) {
		f[i] = (f[i - 1] * i) % MOD;
	}
	f_inv[MAXF - 1] = get_inv(f[MAXF - 1]);
	for(int i = MAXF - 2; i >= 0; i--) {
		f_inv[i] = (f_inv[i + 1] * (i + 1)) % MOD;
	}
}

void solve(){
	int n;
	cin >> n >> MOD;
	gen_f();
	ll ans = 0ll;
	REPN(i, 1, n) {
		ll cur = (f[i] * f[n - i]) % MOD;
		cur = (cur * (n - i + 1)) % MOD;
		cur = (cur * (n - i + 1)) % MOD;
		ans = (ans + cur) % MOD;
	}
	cout << ans << endl;
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