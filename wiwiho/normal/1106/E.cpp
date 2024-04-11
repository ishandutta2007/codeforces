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
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

    int n, m, k;
    cin >> n >> m >> k;

    map<int, vector<pair<int, pii>>> e;
    for(int i = 0; i < k ;i++){
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        e[s].eb(mp(1, mp(w, d)));
        e[t + 1].eb(mp(-1, mp(w, d)));
    }

    multiset<pii, greater<>> now;

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, (1LL << 60)));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(auto j : e[i]){
            if(j.F == 1) now.insert(j.S);
            else now.erase(now.find(j.S));
        }
        pii mx = *now.begin();
        for(int j = 0; j <= m; j++){
            if(now.empty()){
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                continue;
            }
            dp[mx.S][j] = min(dp[mx.S][j], dp[i - 1][j] + mx.F);
            if(j > 0){
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }

    ll ans = (1LL << 60);
    for(int i = 0; i <= m ;i++) ans = min(ans, dp[n][i]);
    cout << ans << "\n";

    return 0;
}