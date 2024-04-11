//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

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

const int N = 1011;

int n, k;
ll x[N];
vector<ll> p[N];
map<ll, int> zbs;

void fail(){
    cout << 0;
    exit(0);
}

void solve(){
    cin >> n >> k;
    if(k == 1)fail();
    vector<int> a;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        Factor::factorize(x[i], p[i]);
        sort(all(p[i]));
        p[i].resize(unique(all(p[i])) - p[i].begin());
        if(p[i].size() > 1u)continue;
        for(ll t: p[i]){
            if(!zbs.count(t))zbs[t] = 1;
            else ++zbs[t];
        }
    }
    int good_primes = 0;
    for(auto [k, v]: zbs)
        if(v >= 2)++good_primes;
    for(int i = 0; i < n; i++){
        bool ok = 1;
        for(ll t: p[i])
            if(zbs[t] < 2)ok = 0;
        if(ok)
            a.push_back(i);
    }
    if(good_primes * 2 < k){
        if(a.size() < k)
            fail();
        bool zadacha_govno[n];
        memset(zadacha_govno, 0, sizeof(zadacha_govno));
        for(int i: a){
            if(p[i].size() == 1u){
                ll pr = p[i][0];
                if(zbs[pr] >= 2 && k){
                    k -= 2;
                    cout << x[i] << ' ';
                    zbs[pr] = 1;
                    zadacha_govno[i] = 1;
                }
                else if(zbs[pr] == 1){
                    cout << x[i] << ' ';
                    zbs[pr] = 0;
                    zadacha_govno[i] = 1;
                }
            }
        }
        for(int i: a){
            if(zadacha_govno[i])continue;
            if(k){
                cout << x[i] << ' ';
                --k;
            }
        }
        cout << endl;
        return;
    }
    if(k&1){
        ll p2 = -1;
        for(auto [k, v]: zbs)
            if(v > 2)p2 = k;
        if(p2 != -1){
            int taken = 0;
            k -= 3;
            for(int i: a){
                if(p[i].size() == 1u){
                    ll pr = p[i][0];
                    if(pr == p2 && taken < 3){
                        ++taken;
                        cout << x[i] << ' ';
                    }
                    if(pr == p2)continue;
                    if(zbs[pr] >= 2 && k){
                        k -= 2;
                        cout << x[i] << ' ';
                        zbs[pr] = 1;
                    }
                    else if(zbs[pr] == 1){
                        cout << x[i] << ' ';
                        zbs[pr] = 0;
                    }
                }
            }
            cout << endl;
            return;
        }
        int pvt = -1;
        for(int i: a){
            if(p[i].size() == 1u)continue;
            if(pvt == -1 || p[i].size() < p[pvt].size())pvt = i;
        }
        if(pvt == -1 || 2 * p[pvt].size() + 1 > k)
            fail();
        --k;
        set<ll> pp;
        for(ll pr: p[pvt])pp.insert(pr);
        cout << x[pvt] << ' ';
        for(int i: a){
            if(p[i].size() != 1u || !pp.count(p[i][0]))
                continue;
            ll pr = p[i][0];
            if(p[i].size() == 1u){
                ll pr = p[i][0];
                if(zbs[pr] >= 2 && k){
                    k -= 2;
                    cout << x[i] << ' ';
                    zbs[pr] = 1;
                }
                else if(zbs[pr] == 1){
                    cout << x[i] << ' ';
                    zbs[pr] = 0;
                }
            }
        }
        for(int i: a){
            if(p[i].size() == 1u){
                ll pr = p[i][0];
                if(pp.count(pr))continue;
                if(zbs[pr] >= 2 && k){
                    k -= 2;
                    cout << x[i] << ' ';
                    zbs[pr] = 1;
                }
                else if(zbs[pr] == 1){
                    cout << x[i] << ' ';
                    zbs[pr] = 0;
                }
            }
        }
    }else{
        for(int i: a){
            if(p[i].size() == 1u){
                ll pr = p[i][0];
                if(zbs[pr] >= 2 && k){
                    k -= 2;
                    cout << x[i] << ' ';
                    zbs[pr] = 1;
                }
                else if(zbs[pr] == 1){
                    cout << x[i] << ' ';
                    zbs[pr] = 0;
                }
            }
        }
    }
    cout << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}