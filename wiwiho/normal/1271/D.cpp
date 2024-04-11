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

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> tmp(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(5001, -1));

    for(int i = 1; i <= n; i++) tmp[i] = i;

    vector<pair<pii, int>> c(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> c[i].F.F >> c[i].F.S >> c[i].S;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        tmp[v] = max(tmp[v], u);
    }

    vector<vector<int>> p(n + 1);
    for(int i = 1; i <= n; i++){
        p[tmp[i]].eb(c[i].S);
    }

    dp[0][k] = 0;

    int ans = -1;
    for(int i = 1; i <= n; i++){
        gsort(p[i]);
        for(int j = c[i].F.F; j <= 5000; j++)
            if(dp[i - 1][j] != -1){
                int now = dp[i - 1][j];
                dp[i][j + c[i].F.S] = max(dp[i][j + c[i].F.S], now);
                for(int k = 0; k < p[i].size() && j + c[i].F.S - k - 1 >= 0; k++){
                    now += p[i][k];
                    dp[i][j + c[i].F.S - k - 1] = max(dp[i][j + c[i].F.S - k - 1], now);
                }
            }
    }
    for(int i = 0; i <= 5000; i++) ans = max(ans, dp[n][i]);
    cout << ans << "\n";

    return 0;
}