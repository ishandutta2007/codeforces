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

vector<ll> f(1000001);

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

ll c(int n, int k){
    if(k > n) return 0;
    return f[n] * inv(f[k]) % MOD * inv(f[n - k]) % MOD;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    map<int, vector<int>> e;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        e[l].eb(i);
        e[r].eb(-i);
    }

    f[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        f[i] = f[i - 1] * i % MOD;
    }

    set<int> now;
    ll ans = 0;
    for(auto& i : e){
        gsort(i.S);
        for(int j : i.S){
            if(j > 0){
                ans += c(now.size(), k - 1);
                ans %= MOD;
//                cerr << j << "  ";
//                printv(now, cerr);
                now.insert(j);
            }
            else now.erase(-j);
        }
    }
    cout << ans << "\n";
//
    return 0;
}