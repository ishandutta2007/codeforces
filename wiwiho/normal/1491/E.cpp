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

vector<int> f;

vector<vector<int>> g;
vector<bool> del;
vector<pii> e;

int ano(int v, int id){
    return e[id].F ^ e[id].S ^ v;
}

vector<int> sz;
vector<int> top;
vector<int> tv;
void dfs(int now, int p){
    top[now] = p;
    sz[now] = 1;
    tv.eb(now);
    for(int i : g[now]){
        if(i == p || del[i]) continue;
        dfs(ano(now, i), i);
        sz[now] += sz[ano(now, i)];
    }
}

bool check(int now){

    tv.clear();
    dfs(now, 0);

    auto it = lower_bound(iter(f), sz[now]);
    if(it == f.end() || *it != sz[now]) return false;

    int id = it - f.begin();
    if(id <= 2) return true;
    for(int i : tv){
        if(sz[i] == f[id - 1] || sz[i] == f[id - 2]){
            del[top[i]] = true;
            return check(i) && check(now);
        }
    }

    return false;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    f.eb(1);
    f.eb(1);
    for(int i = 2; f[i - 1] + f[i - 2] <= n; i++) f.eb(f[i - 1] + f[i - 2]);

    sz.resize(n + 1);
    top.resize(n + 1);
    g.resize(n + 1);
    e.resize(n);
    del.resize(n);
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(i);
        g[v].eb(i);
        e[i] = mp(u, v);
    }

    if(check(1)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}