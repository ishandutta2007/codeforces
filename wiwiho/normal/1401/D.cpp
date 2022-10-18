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

vector<vector<int>> g;
vector<int> sz;

void dfs(int now, int p){
    sz[now] = 1;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
        sz[now] += sz[i];
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        g.clear();
        sz.clear();
        g.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }

        dfs(1, 1);

        vector<ll> t;
        for(int i = 2; i <= n; i++){
            t.eb((ll)sz[i] * (sz[1] - sz[i]));
        }
//        printv(t, cerr);
        lsort(t);

        int m;
        cin >> m;
        vector<ll> p(m);
        for(int i = 0; i < m; i++){
            cin >> p[i];
        }
        if(p.size() < n - 1){
            p.resize(n - 1, 1);
            m = n - 1;
        }

        lsort(p);

//        printv(t, cerr);
//        printv(p, cerr);

        ll ans = 0;
        for(int i = 0; i < n - 1 - 1; i++){
            ans += t[i] % MOD * p[i] % MOD;
            ans %= MOD;
        }

        for(int i = n - 1; i < m; i++){
            p[n - 2] = p[n - 2] * p[i] % MOD;
        }

        ans += t[n - 2] % MOD * p[n - 2] % MOD;
        ans %= MOD;

        cout << ans << "\n";

    }

    return 0;
}