
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

int n;
vector<ll> dp1, dp2, l, r;
vector<vector<int>> g;

void dfs(int now, int p){
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
        dp1[now] += max(dp1[i] + abs(l[i] - l[now]), dp2[i] + abs(r[i] - l[now]));
        dp2[now] += max(dp1[i] + abs(l[i] - r[now]), dp2[i] + abs(r[i] - r[now]));
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        cin >> n;
        dp1.clear();
        dp2.clear();
        l.clear();
        r.clear();
        g.clear();
        dp1.resize(n + 1);
        dp2.resize(n + 1);
        l.resize(n + 1);
        r.resize(n + 1);
        g.resize(n + 1);

        for(int i = 1; i <= n; i++){
            cin >> l[i] >> r[i];
        }

        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }

        dfs(1, 1);
        cout << max(dp1[1], dp2[1]) << "\n";
    }

    return 0;
}