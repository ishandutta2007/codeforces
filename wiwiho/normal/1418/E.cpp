//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<ll> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x, ll v){
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] += v;
        BIT[x] = (BIT[x] % MOD + MOD) % MOD;
    }
}

ll query(int x){
    ll ans = 0;
    for(; x > 0; x -= lowbit(x)){
        ans += BIT[x];
        ans %= MOD;
    }
    return ans;
}

ll inv(ll a){
    ll b = MOD - 2;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    BIT.resize(n + 1);

    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++) cin >> d[i];
    lsort(d);

    for(int i = 1; i <= n; i++){
        modify(i, d[i]);
    }

    for(int i = 0; i < m; i++){

        int a, b;
        cin >> a >> b;

        int big = (int) (lower_bound(iter(d), b) - d.begin()) - 1;
        big = n - big;

        ll ans = (query(n) - query(n - big)) * max(big - a, 0) % MOD * inv(big) % MOD;
        ans += query(n - big) * max(big + 1 - a, 0) % MOD * inv(big + 1) % MOD;
        ans %= MOD;
        ans = (ans % MOD + MOD) % MOD;
        cout << ans << "\n";

    }

    return 0;
}