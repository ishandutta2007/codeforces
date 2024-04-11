//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
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
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<ll> f, fi, p;

ll inv(ll base){
    ll b = MOD - 2;
    ll now = 1;
    while(b > 0){
        if(b & 1) now = now * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return now;
}

ll calc(ll a){
    ll ans = 1, sum = 0;
    for(ll i : p){
        if(a % i) continue;
        ll cnt = 0;
        while(a % i == 0) cnt++, a /= i;
        sum += cnt;
        ans = ans * fi[cnt] % MOD;
    }
    ans = ans * f[sum] % MOD;
    return ans;
}

int main(){
    StarBurstStream

    ll d;
    cin >> d;

    f.resize(101);
    fi.resize(101);
    f[0] = 1;
    for(int i = 1; i <= 100; i++) f[i] = f[i - 1] * i % MOD;
    for(int i = 0; i <= 100; i++) fi[i] = inv(f[i]);

    for(ll i = 2; i * i <= d; i++){
        if(d % i) continue;
        p.eb(i);
        while(d % i == 0) d/= i;
    }
    if(d > 1) p.eb(d);
//    printv(p, cerr);

    int q;
    cin >> q;

    while(q--){
        ll u, v;
        cin >> u >> v;
        ll g = __gcd(u, v);
        cout << calc(u / g) * calc(v / g) % MOD << "\n";
    }

    return 0;
}