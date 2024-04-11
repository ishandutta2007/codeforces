//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const long long mod = (119<<23) + 1;
const long long maxpw = 1<<23;

inline long long powmod(long long x, long long pw){
	long long res = 1;
	while(pw){
		if(pw&1)res = res * x % mod;
		x = x * x % mod;
		pw >>= 1;
	}
	return res;
}

const long long root = powmod(3, 119);
const long long root_inv = powmod(root, mod - 2);

//also 5 * 2^25 + 1, 3^5 and 7 * 2^26 + 1, 3^7

vector<long long> root_pw[30];
vector<long long> root_inv_pw[30];

void NTT_prepare(int max_lg){
	long long wn = root;
	for(int i = max_lg; i < __builtin_ctz(maxpw); i++)
		wn = wn * wn % mod;
	for(int i = max_lg; i >= 1; i--){
		root_pw[i].resize(1<<(i - 1));
		long long w = 1;
		for(int j = 0; j < (int)root_pw[i].size(); j++){
			root_pw[i][j] = w;
			w = w * wn % mod;
		}
		wn = wn * wn % mod;
	}
	wn = root_inv;
	for(int i = max_lg; i < __builtin_ctz(maxpw); i++)
		wn = wn * wn % mod;
	for(int i = max_lg; i >= 1; i--){
		root_inv_pw[i].resize(1<<(i - 1));
		long long w = 1;
		for(int j = 0; j < (int)root_inv_pw[i].size(); j++){
			root_inv_pw[i][j] = w;
			w = w * wn % mod;
		}
		wn = wn * wn % mod;
	}
}

void NTT(long long * from, long long * to, bool inv){
	int n = to - from;
	int lg = __builtin_ctz(n);
	for(int i = 0; i < n; i++){
		int rev = 0;
		int k = lg - 1;
		for(int j = 0; j < lg; j++){
			rev |= i&(1<<j) ? 1<<k : 0;
			--k;
		}
		if(i < rev)swap(*(from + i), *(from + rev));
	}
	lg = 0;
	for(int len = 2; len <= n; len <<= 1){
		++lg;
		vector<long long> & w = inv ? root_inv_pw[lg] : root_pw[lg];
		for(int i = 0; i < n; i += len){
			long long *l = from + i, *r = from + i + len/2;
			for(int j = 0; j < len/2; j++){
				long long u = *l, v = *r * w[j] % mod;
				*l = u + v;
				*r = u - v;
				*l -= *l >= mod ? mod : 0;
				*r += *r < 0 ? mod : 0;
				++l; ++r;
			}
		}
	}
	if(inv){
		long long ni = powmod(n, mod - 2);
		for(long long * curr = from; curr != to; curr++)
			*curr = *curr * ni % mod;
	}
}

const int SZ = 1<<21;

ll p[SZ];

void solve(){
    NTT_prepare(21);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++){
        int d;
        scanf("%d", &d);
        p[d] = 1;
    }
    NTT(p, p + SZ, 0);
    for(int i = 0; i < SZ; i++){
        p[i] = powmod(p[i], n/2);
    }
    NTT(p, p + SZ, 1);
    ll ans = 0;
    for(int i = 0; i < SZ; i++){
        ans += p[i] * p[i] % mod;
    }
    ans = (ans%mod + mod)%mod;
    printf("%lld\n", ans);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}