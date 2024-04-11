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

ll inv(ll n){
    ll t = MOD - 2;
    ll now = 1;
    ll base = n;
    while(t > 0){
        if(t & 1) now = base * now % MOD;
        base = base * base % MOD;
        t >>= 1;
    }
    return now;
}

ll c(ll n, ll k){
    ll ans = 1;
    for(int i = k + 1; i <= n; i++) ans = ans * i % MOD;
    for(int i = 1; i <= n - k; i++) ans = ans * inv(i) % MOD;
    return ans;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    ll ans = 0;
    for(int i = n; i > n - k; i--) ans += i;

    ll ans2 = 1;
    vector<int> pos;
    for(int i = 0; i < n; i++) if(p[i] > n - k) pos.eb(i);
    for(int i = 1; i < k; i++){
        ans2 = ans2 * (pos[i] - pos[i - 1]) % MOD;
    }

    cout << ans << " " << ans2 << "\n";

    return 0;
}