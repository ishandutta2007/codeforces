#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i < r; i++)
#define DF(i, l, r) for(int i = l; i >= r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
#define asg assign
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg
#define link kekekeke

const int mod = 1000000007;
const int MK = 5005;

ll fac[MK];

void gcdex(ll a, ll b, ll & x, ll & y){
	if(a == 0){x = 0; y = 1; ret;}
	ll x1, y1;
	gcdex(b%a, a, x1, y1);
	y = x1;
	x = y1 - (b/a) * x1;
}

ll inv(ll a){
	ll x, y;
	gcdex(a, mod, x, y);
	ret (x%mod + mod)%mod;
}

ll small_c(int n, int k){
	if(n < k)ret 0;
	else ret fac[n] * inv(fac[n - k] * fac[k] % mod) % mod;
}

ll binpow(ll x, ll n){
	ll res = 1;
	while(n){
		if(n&1)res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	ret res;
}

void solve_small(int n, int k){
	ll ans = 0;
	F(i, 1, n + 1){
		ll cu = small_c(n, i);
		ll pw = binpow(i, k);
		ans += cu * pw % mod;
	}
	cout << ans%mod;
}

ll coeff[2][MK + 228];
ll der[MK + 228];
int sz[2];

void solve_big(int n, int k){
	sz[0] = 1;
	coeff[0][0] = 1;
	F(i, 0, k){
		F(j, 0, sz[0])coeff[1][j] = coeff[0][j] * (n - i) % mod;
		F(j, 1, sz[0])der[j - 1] = coeff[0][j] * j;
		F(j, 0, sz[0] - 1)coeff[1][j] = (coeff[1][j] + der[j]);
		F(j, 1, sz[0])coeff[1][j] = (coeff[1][j] + der[j - 1]);
		F(j, 0, sz[0])coeff[1][j] %= mod;
		sz[0]++;
		coeff[0][0] = 0;
		F(j, 1, sz[0])coeff[0][j] = coeff[1][j - 1];
	}
	ll kek = 0;
	F(i, 0, sz[0]){kek += coeff[0][i];}
	kek %= mod;
	ll pw = binpow(2, n - k);
	kek = kek * pw % mod;
	cout << kek;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fac[0] = 1;
	F(i, 1, MK)fac[i] = fac[i - 1] * i % mod;
	int n, k;
	cin >> n >> k;
	if(n <= k)solve_small(n, k);
	else solve_big(n, k);
	return 0;
}