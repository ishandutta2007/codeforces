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
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

//GCC only
namespace Factor{
	const int CNT_SMALL_PRIMES = 12;
	const int SMALL_PRIMES[CNT_SMALL_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	std::mt19937_64 random_gen(std::chrono::steady_clock::now().time_since_epoch().count());
	inline ll gcd(ll a, ll b){
		if(b == 0)
			return a;
		int shift = __builtin_ctzll(a | b);
		b >>= __builtin_ctzll(b);
		while(a){
			a >>= __builtin_ctzll(a);
			if(a < b)
				std::swap(a, b);
			a -= b;
		}
		return b<<shift;
	}
	inline ll abs(ll a){
		return a < 0 ? -a : a;
	}
	inline ll mul_mod(ll a, ll b, ll mod){
	#if defined(__LP64__) || defined(_WIN64)
		return __int128(a) * b % mod;
	#else
		ll res = 0;
		while(b){
			if(b&1){res += a; res -= res >= mod ? mod : 0;}
			a += a;
			a -= a >= mod ? mod : 0;
			b >>= 1;
		}
		return res;
		//or calculate in doubles for speed
	#endif
	}
	inline ll pw(ll a, ll to, ll mod){
		ll res = 1;
		while(to){
			if(to&1)
				res = mul_mod(res, a, mod);
			a = mul_mod(a, a, mod);
			to >>= 1;
		}
		return res;
	}
	inline bool miller_rabin(ll n, ll a){
		a %= n;
		if(a < 2 || a == n - 1)return false;
		int shift = __builtin_ctzll(n - 1);
		ll t = (n - 1)>>shift;
		ll kek = pw(a, t, n);
		if(kek == 1)
			return false;
		if(kek == n - 1)
			return false;
		for(int i = 1; i < shift; i++){
			kek = mul_mod(kek, kek, n);
			if(kek == 1)
				return true;
			if(kek == n - 1)
				return false;
		}
		return true;
	}
	inline bool test_prime(ll n){
		if(n == 1)
			return false;
		for(int i = 0; i < CNT_SMALL_PRIMES && SMALL_PRIMES[i] < n; i++){
			if(miller_rabin(n, SMALL_PRIMES[i]))
				return false;
		}
		return true;
	}
	inline ll G(ll x, ll mod){
		x = mul_mod(x, x, mod);
		++x;
		x -= x == mod ? mod : 0;
		return x;
	}
	inline void factorize(ll n, std::vector<ll> & p){
		if(n == 1)
			return;
		if(test_prime(n)){
			p.push_back(n);
			return;
		}
		for(int i = 0; i < CNT_SMALL_PRIMES; i++){
			if(n%SMALL_PRIMES[i] == 0){
				p.push_back(SMALL_PRIMES[i]);
				factorize(n/SMALL_PRIMES[i], p);
				return;
			}
		}
		while(true){
			ll x = random_gen()%(n - 1) + 1;
			ll y = G(x, n);
			int a = 1, b = 2;
			while(true){
				ll d = x - y;
				d += d < 0 ? n : 0;
				if(!d)
					break;
				ll g = gcd(d, n);
				if(g != 1){
					factorize(g, p);
					factorize(n/g, p);
					return;
				}
				if(a * 2 == b){
					a *= 2;
					x = y;
				}
				++b;
				y = G(y, n);
			}
		}
	}
}
const int N = (int)1e6 + 6;

int dp[N];
int old[N];
ll n;
ll divs[N];
ll p[N];
ll big[N];
ll idx[N];
vector<pair<ll, ll> > tran;
int sz = 0;

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i * i <= n; i++){
        if(n%i)
            continue;
        divs[sz++] = i;
        if(i * i != n)
            divs[sz++] = n/i;
    }
    sort(divs, divs + sz);
    for(int i = 0; i < sz; i++){
        if(divs[i] < N)
            idx[divs[i]] = i;
        else
            big[n/divs[i]] = i;
        if(divs[i] - 1 <= 1)
            continue;
        vector<ll> tmp;
        Factor::factorize(divs[i] - 1, tmp);
        if(unique(all(tmp)) != tmp.begin() + 1)
            continue;
        tran.emplace_back(tmp[0], divs[i]);
    }
    sort(all(tran));
    old[0] = 1;
    size_t ptr = 0;
    while(ptr < tran.size()){
        size_t j = ptr;
        memcpy(dp, old, sz * sizeof(dp[0]));
        while(j < tran.size() && tran[j].X == tran[ptr].X){
            ll div = tran[j].Y;
            for(int i = 0; i < sz; i++){
                if(divs[i]%div)
                    continue;
                ll prv = divs[i]/div;
                int k = prv < N ? idx[prv] : big[n/prv];
                dp[i] += old[k];
            }
            ++j;
        }
        memcpy(old, dp, sz * sizeof(dp[0]));
        ptr = j;
    }
    cout << old[n < N ? idx[n] : big[1]] << endl;
    return 0;
}