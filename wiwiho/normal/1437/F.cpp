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

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    lsort(a);
//    printv(a, cerr);

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    dp[0][0] = 1;
    vector<vector<ll>> cnt(n + 1, vector<ll>(n + 1));
    cnt[0][0] = 1;

    for(int i = 1; i <= n; i++){
        int l = upper_bound(iter(a), a[i] / 2) - a.begin() - 1;
//        cerr << i << " " << l << "\n";
        for(int j = 1; j <= l + 1; j++){
            dp[i][j] += cnt[l][j - 1];
            dp[i][j] += dp[i][j - 1] * (l + 1 - (j - 1)) % MOD;
            dp[i][j] %= MOD;
        }
//        printv(dp[i], cerr);
        for(int j = 0; j <= n; j++){
            cnt[i][j] = cnt[i - 1][j] + dp[i][j];
            cnt[i][j] %= MOD;
        }
    }

    cout << dp[n][n] << "\n";

    return 0;
}