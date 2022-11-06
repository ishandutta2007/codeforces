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
const ll MOD = 1e9 + 7;

const int MAXN = 55;

struct frac {
	ll p, q;
	frac() {}
	frac(ll _p, ll _q) { p = _p, q = _q; }
};

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

ll get_rev(ll v) {
	return pow_mod(v, MOD - 2);
}

frac operator + (const frac &a, const frac &b) {
	frac c = frac((a.p * b.q + b.p * a.q) % MOD, (a.q * b.q) % MOD);
	//cout << "+ " << a.p << " " << a.q << " " << b.p << " " << b.q << " " << c.p << " " << c.q << " " << endl;
	return c;
}

frac operator * (const frac &a, const frac &b) {
	frac c = frac((a.p * b.p) % MOD, (a.q * b.q) % MOD);
	//cout << "* " << a.p << " " << a.q << " " << b.p << " " << b.q << " " << c.p << " " << c.q << " " << endl;
	return c;
}

map<ll, frac> dp, dp_tmp;
frac dp0[MAXN], dp1[MAXN];
ll stp[MAXN];

ll k;

void add_div(ll div, ll &n) {
	int cnt = 0;
	for(; n % div == 0; n /= div, cnt++);
	stp[0] = 1ll;
	REPN(i, 1, cnt) {
		stp[i] = stp[i - 1] * div;
	}	
	dp0[cnt] = frac(1ll, 1ll);
	REP(i, 0, cnt) {
		dp0[i] = frac(0ll, 1ll);
	}
	REPN(l, 1, k) {
		/*REPN(i, 0, cnt) {
			cout << i << " " << dp0[i].p << " " << dp0[i].q << endl;
		}
		cout << endl;*/
		
		REPN(i, 0, cnt) {
			dp1[i] = frac(0ll, 1ll);
		}
		REPN(i, 0, cnt) {
			REPN(j, 0, i) {
				dp1[j] = (dp1[j] + dp0[i] * frac(1ll, (ll)(i + 1)));
			}
			/*REPN(t, 0, cnt) {
				cout << t << " " << dp1[t].p << " " << dp1[t].q << endl;
			}
			cout << endl;*/
		}
		REPN(i, 0, cnt) {
			dp0[i] = dp1[i];
		}
		
		/*REPN(i, 0, cnt) {
			cout << i << " " << dp0[i].p << " " << dp0[i].q << endl;
		}
		cout << endl;*/
	}
	dp_tmp.clear();
	FA(it, dp) {
		REPN(i, 0, cnt) {
			ll new_div = it->_1 * stp[i];
			frac dp_val = it->_2 * dp0[i];
			dp_tmp[new_div] = dp_val;
		}
	}
	dp = dp_tmp;
	
	/*FA(it, dp) {
		cout << it->_1 << " " << it->_2.p << " " << it->_2.q << endl;
	}
	cout << endl;*/
}

void process(ll n) {
	dp[1] = frac(1ll, 1ll);
	for(ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			add_div(i, n);
		}
	}
	if (n > 1) {
		add_div(n, n);
	}
}

void solve(){
	ll n;
	cin >> n >> k;
	process(n);
	frac ans(0, 1);
	FA(it, dp) {
		frac tmp = frac(it->_1 % MOD, 1);
		ans = ans + tmp * it->_2;
		//cout << it->_1 << " " << it->_2.p << " " << it->_2.q << endl;
	}
	ll v = (ans.p * get_rev(ans.q)) % MOD;
	cout << v << endl;
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