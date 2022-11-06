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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll pow_mod(ll v, ll st){
	ll ans = 1ll, a = v;
	for(; st; st >>= 1){
		if (st & 1){
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

ll get_inv(ll a){
	return pow_mod(a, MOD - 2ll);
}

void solve(){
	ll m, n, ans;
	cin >> n >> m;
	if (m == 1){
		ans = n + 1;
	} else {
		ll tmp1 = pow_mod(m, n);
		ll tmp2 = pow_mod(2ll * m - 1, n);
		ll tmp3 = (tmp2 - tmp1 + MOD) % MOD;
		ll tmp4 = (tmp3 * m) % MOD;
		ll tmp5 = get_inv(m - 1);
		ll tmp6 = (tmp4 * tmp5) % MOD;
		ans = (tmp1 + tmp6) % MOD;
	}
	cout << ans << endl;	
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}