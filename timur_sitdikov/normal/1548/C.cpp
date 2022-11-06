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
// const ll MOD = 998244353;

const int MAXF = 3e6 + 5;

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

ll get_c(int i, int j) {
	if (j > i || j < 0) {
		return 0ll;
	}
	return (((f[i] * f_inv[j]) % MOD) * f_inv[i - j]) % MOD;
}

ll x[MAXF], y[MAXF], z[MAXF];
ll _3;
int n;

void process(int ind) {
	ll a = z[ind - 1];
	ll b = x[ind - 1];
	ll c = get_c(3 * n + 1, ind + 1);
	/*if (ind % 3 == 0) {
		
	} else if (ind % 3 == 1) {
	
	} else {
		
	}*/
	b = (b - get_c(3 * n + 1, ind) + MOD) % MOD;
	x[ind] = ((c + a - b + MOD) % MOD * _3) % MOD;
	y[ind] = (x[ind] + b) % MOD;
	z[ind] = (x[ind] - a + MOD) % MOD;
}

void solve(){
	gen_f();
	_3 = pow_mod(3, MOD - 2);
	scanf("%d", &n);
	x[0] = n + 1;
	y[0] = n;
	z[0] = n;
	REPN(i, 1, 3 * n) {
		process(i);
	}
	/*REPN(i, 0, 3 * n) {
		printf("%lld %lld %lld\n", x[i], y[i], z[i]);
	}*/
	int q;
	scanf("%d", &q);
	while(q--) {
		int v;
		scanf("%d", &v);
		printf("%lld\n", x[v]);
	}
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