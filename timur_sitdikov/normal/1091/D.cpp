#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 998244353;

const int MAXN = 1e6 + 5;

ll f[MAXN], f_inv[MAXN];

ll pow_mod(ll a, ll st) {
	ll ans = 1ll;
	for(; st; st /= 2ll) {
		if (st & 1) {
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	f[0] = 1;
	REPN(i, 1, n) {
		f[i] = (f[i - 1] * i) % MOD;
	}
	f_inv[n] = pow_mod(f[n], MOD - 2);
	for(int i = n - 1; i >= 0; i--) {
		f_inv[i] = (f_inv[i + 1] * (i + 1)) % MOD;
		//printf("%lld\n", f_inv[i]);
	}
	ll ans = 1ll;
	REP(i, 2, n) {
		ll cur = ((f[i] + MOD - 1) * f_inv[i]) % MOD;
		ans = (ans + cur) % MOD;
	}
	ans = (ans * f[n]) % MOD;
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