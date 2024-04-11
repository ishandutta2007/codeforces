//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1LL << 60;

ll fp(ll base, ll n){
    ll ans = 1;
    for(ll i = 0; (1LL << i) <= n; i++){
        if((1LL << i) & n) ans = modtimes(ans, base);
        base = modtimes(base, base);
    }
    return ans;
}

vector<int> prime;
vector<int> ps;
void sieve(int n){
    prime.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(prime[i] == 1){
            ps.push_back(i);
            prime[i] = i;
        }
        for(int j : ps){
            if((ll)i * j > n || j > prime[i]) break;
            prime[i * j] = j;
        }
    }
}

int main(){
    StarBurstStream

    ll x, n;
    cin >> x >> n;

    sieve(1000000);
    ll ans = 1;
    vector<ll> p;
    for(ll t : ps){
        if(x % t == 0){
            p.pb(t);
            while(x % t == 0){
                x /= t;
            }
        }
    }
    if(x > 1) p.pb(x);
    printv(p, cerr);

    for(ll i : p){
        ll now = 1, t = 0;
        while(now <= n / i) now *= i;
        while(now > 1){
            ll tt = n / now;
            tt -= t;
            t += tt;
            ll abc = fp(now, tt);
            //cerr << i << " " << now << " " << t << " " << tt << " " << abc << "\n";
            ans = modtimes(ans, abc);
            now /= i;
        }
    }

    cout << ans << "\n";

    return 0;
}