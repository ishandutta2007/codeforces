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

ll fp(ll a, ll b){
    ll now = 1;
    ll base = a;
    while(b > 0){
        if(b & 1) now = now * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return now;
}

ll inv(ll a){
    return fp(a, MOD - 2);
}

vector<ll> f(300001);
ll c(ll n, ll k){
    return f[n] * inv(f[k]) % MOD * inv(f[n - k]) % MOD;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    if(n <= 2){
        cout << "0\n";
        return 0;
    }

    f[0] = 1;
    for(int i = 1; i <= 300000; i++) f[i] = f[i - 1] * i % MOD;

    ll ans = 0;
    for(int i = n - 1; i <= m; i++){
        ans += (i - 1) * c(i - 2, n - 3) % MOD * fp(2, n - 3) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";

    return 0;
}