#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; i++)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; i--)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int N = (int)1e5 + 5;
const int mod = (int)1e9 + 7;

ll pwsum[N + 1];
ll fac[N + 1];
ll ifac[N + 1];
int n, k;
string s;

ll C(int n, int k){
	if(k < 0)ret 0;
	if(n < k)ret 0;
	return fac[n] * (ifac[n - k] * ifac[k] % mod)%mod;
}

ll inv(ll x){
	ll res = 1, pw = mod - 2;
	while(pw){
		if(pw&1)res = res * x % mod;
		x = x * x % mod;
		pw >>= 1;
	}
	ret res;
}

signed main() {
    sync;
	fac[0] = ifac[0] = 1;
	F(i, 1, N + 1){
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv(i) % mod;
	}
	cin >> n >> k;
	cin >> s;
	ll curr = 1;
	F(i, 0, N + 1){
		if(n - 1 - i - 1 >= 0)
			pwsum[i] = curr * C(n - 1 - i - 1, k - 1) % mod;
		if(i)pwsum[i] = (pwsum[i] + pwsum[i - 1])%mod;
		curr = curr * 10 % mod;
	}
	ll ans = 0;
	ll pw10 = 1;
	DF(i, n - 1, 0){
		int mxpw = n - 1 - i;
		if(mxpw)ans += (s[i] - '0') * pwsum[mxpw - 1] % mod;
		ll coeff = (s[i] - '0') * pw10 % mod;
		coeff = coeff * C(n - 1 - mxpw, k) % mod;
		ans = (ans + coeff)%mod;
		pw10 = pw10 * 10 % mod;
	}
	cout << ans;
}