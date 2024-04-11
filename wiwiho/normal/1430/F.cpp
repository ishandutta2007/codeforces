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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
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

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<ll> l(n), r(n), a(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i] >> a[i];

    ll ans = 1LL << 60;
    vector<ll> dp(n + 1, 1LL << 60);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        ll rm = k, t = dp[i];
        for(int j = i; j < n; j++){
            ll cnt = iceil(max(0LL, a[j] - rm), k);
//            cerr << i << " " << j << " " << dp[i] << " " << cnt << "\n";
            if(cnt > r[j] - l[j]) break;
            rm = rm + cnt * k - a[j];
            t += a[j];
            if(j != n - 1 && l[j] + cnt < l[j + 1]) tomin(dp[j + 1], t + rm);
            if(j == n - 1) ans = min(ans, t);
        }
    }

    if(ans == (1LL << 60)) ans = -1;
    cout << ans << "\n";

    return 0;
}