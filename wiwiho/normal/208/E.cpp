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

int main(){
    StarBurstStream

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    const int SZ = 20;
    vector<vector<int>> anc(SZ, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        g[p].eb(i);
        anc[0][i] = p;
    }
    
    for(int i = 1; i < SZ; i++){
        for(int j = 1; j <= n; j++){
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }

    auto getanc = [&](int v, int k){
        for(int i = 0; i < SZ; i++){
            if(1 << i & k) v = anc[i][v];
        }
        return v;
    };

    int m;
    cin >> m;
    vector<vector<pii>> qry(n + 1);
    vector<int> ans(m);

    for(int i = 0; i < m; i++){
        int v, p;
        cin >> v >> p;
        v = getanc(v, p);
        if(v != 0) qry[v].eb(mp(p, i));
    }

    vector<vector<int>> dp(n + 1);
    function<void(int)> dfs;
    dfs = [&](int now){
        dp[now].eb(1);
        for(int i : g[now]){
            dfs(i);
            dp[i].eb(0);
            if(dp[now].size() < dp[i].size()) dp[now].swap(dp[i]);
            /*cerr << "merge\n";
            printv(dp[now], cerr);
            printv(dp[i], cerr);*/
            for(int j = 0; j < dp[i].size(); j++){
                dp[now][dp[now].size() - 1 - j] += dp[i][dp[i].size() - 1 - j];
            }
            //printv(dp[now], cerr);
        }
        for(pii i : qry[now]){
            ans[i.S] = dp[now][dp[now].size() - 1 - i.F] - 1;
        }
        /*cerr << "dp " << now << "  ";
        printv(dp[now], cerr);*/
    };
    dfs(0);

    printv(ans, cout);

    return 0;
}