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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

vector<int> prime, lpf;

void sieve(int n){
    lpf.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(lpf[i] == 1){
            lpf[i] = i;
            prime.eb(i);
        }
        for(int j : prime){
            if((ll)i * j > n) break;
            lpf[i * j] = j;
            if(j == lpf[i]) break;
        }
    }
}

const int SZ = 1000000;

int main(){
    StarBurstStream

    int n;
    cin >> n;
    sieve(SZ);

    vector<ll> dp(SZ + 1);
    vector<bool> use(SZ + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        use[a] = true;
    }

    auto calc = [&](int v){
        int cnt = 0;
        
        for(int i = v * 2; i <= SZ; i += v){
            if(use[i]) cnt++;
        }
        ll sum = (ll)cnt * (cnt + 1) / 2;

        for(int i = v * 2; i <= SZ; i += v){
            sum -= dp[i];
        }

        if(sum - cnt > 0) use[v] = true;

        if(use[v]) dp[v] = sum;
        else dp[v] = sum - cnt;
    };

    for(int i = SZ; i >= 1; i--){
        calc(i);
        if(use[i]) ans++;
    }
    ans -= n;
    cout << ans << "\n";

    return 0;
}