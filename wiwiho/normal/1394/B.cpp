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
#define topos(a) (((a) % MOD + MOD) % MOD)

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

int n, m, k;
ll tmp = 0;
ll ans = 0;
vector<ll> two;
//vector<int> tt;
void dfs(int now, vector<vector<ll>>& t){
    if(now == k + 1){
//        cerr << bitset<10>(tmp).to_string() << "  ";
//        printv(tt, cerr);
        if(tmp == topos(two[n + 1] - 2)) ans++;
        return;
    }
    for(int i = 1; i <= now; i++){
        tmp += t[now][i];
        tmp %= MOD;
//        tt.eb(i);
        dfs(now + 1, t);
        tmp -= t[now][i];
        tmp = (tmp % MOD + MOD) % MOD;
//        tt.pob;
    }
}

int main(){
    StarBurstStream

    cin >> n >> m >> k;

    vector<vector<pii>> g(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(mp(w, v));
    }

    two.resize(n +  2);
    two[0] = 1;
    for(int i = 1; i <= n + 1; i++) two[i] = two[i - 1] * 2 % MOD;
//    printv(two, cerr);

    vector<vector<ll>> t(k + 1, vector<ll>(k + 1));
    for(int i = 1; i <= n; i++){
        lsort(g[i]);
        for(int j = 0; j < g[i].size(); j++){
//            cerr << g[i].size() << " " << j + 1 << " " << g[i][j] << "\n";
            t[g[i].size()][j + 1] += two[g[i][j].S];
            t[g[i].size()][j + 1] %= MOD;
        }
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= i; j++){
//            cerr << i << " " << j << " " << bitset<10>(t[i][j]).to_string() << "\n";
        }
    }

    dfs(1, t);

    cout << ans << "\n";

    return 0;
}