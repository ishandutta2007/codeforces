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

bool comp(vector<ll>& a, vector<ll>& b){
    return a.size() > b.size();
}

int n, k;

vector<vector<int>> g;

void dfs(int now, int p, vector<ll>& dp){

    vector<vector<ll>> c;
    for(int i : g[now]){
        if(i == p) continue;
        vector<ll> tdp;
        dfs(i, now, tdp);
        c.eb();
        ll sum = 0;
        for(ll j : tdp) sum = (sum + j) % MOD;
        c.back().eb(sum);
        for(ll j : tdp){
            c.back().eb(j);
        }
        if(c.back().size() > k + 1) c.back().resize(k + 1);
    }

    if(c.empty()){
        dp.eb(1);
//        cerr << now << "  ";
//        printv(dp, cerr);
        return;
    }
    if(c.size() == 1){
        dp = c[0];
//        cerr << now << "  ";
//        printv(dp, cerr);
        return;
    }

    sort(iter(c), comp);
    dp.resize(c[0].size());
    int sz = c.size();

    for(int i = 0; i < sz; i++){
        for(int dpt = 0; dpt < c[i].size(); dpt++){
            ll tmp = c[i][dpt];
            for(int j = 0; j < sz; j++){
                if(i == j) continue;
                ll tt = 0;
                for(int d = 0; d < c[j].size() && d + dpt <= k && d <= dpt; d++){
                    if(d == dpt && j < i) continue;
                    tt += c[j][d];
                    tt %= MOD;
                }
                tmp = tmp * tt % MOD;
            }
            dp[dpt] += tmp;
            dp[dpt] %= MOD;
        }
    }

//    cerr << now << "  ";
//    printv(dp, cerr);
}

int main(){
    StarBurstStream

    cin >> n >> k;

    g.resize(n + 1);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    vector<ll> dp;
    dfs(1, 1, dp);
    ll ans = 0;
    for(int i = 0; i <= k && i < dp.size(); i++){
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << "\n";

    return 0;
}