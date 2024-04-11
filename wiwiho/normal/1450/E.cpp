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

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<pii>> g;
vector<int> c;
bool ok = true;

void dfs(int now, int clr){
    c[now] = clr;
    for(pii i : g[now]){
        if(c[i.F] != -1){
            if(c[i.F] == clr) ok = false;
            continue;
        }
        dfs(i.F, !clr);
    }
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    c.resize(n + 1, -1);
    for(int i = 0; i < m; i++){
        int u, v, b;
        cin >> u >> v >> b;
        if(b == 1) g[u].eb(mp(v, 1)), g[v].eb(mp(u, -1));
        else g[u].eb(mp(v, 1)), g[v].eb(mp(u, 1));
    }

    dfs(1, 0);

    if(!ok){
        cout << "NO\n";
        return 0;
    }

    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, MAX));
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int i = 1; i <= n; i++){
        for(pii j : g[i]) dis[i][j.F] = j.S;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dis[i][i] < 0) ok = false;
    }

    if(!ok){
        cout << "NO\n";
        return 0;
    }

    ll mx = -1;
    int tmp = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dis[i][j] > mx){
                mx = dis[i][j];
                tmp = i;
            }
        }
    }

    cout << "YES\n";
    cout << mx << "\n";
    for(int i = 1; i <= n; i++){
        cout << dis[tmp][i] << " ";
    }
    cout << "\n";

    return 0;
}