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

vector<vector<int>> g;

int f = -1, fv = -1;

void dfs(int now, int p, int d){
    if(d > fv) f = now, fv = d;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now, d + 1);
    }
}

int a, b;
vector<int> tmp;

bool dfs2(int now, int p){
    bool ok = now == b;
    for(int i : g[now]){
        if(i == p) continue;
        ok |= dfs2(i, now);
    }
    if(ok) tmp.eb(now);
    return ok;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1, 1, 0);
    fv = -1;
    a = f;
    dfs(f, f, 0);
    b = f;

    dfs2(a, a);
//    cerr << a << " " << b << "\n";

    queue<int> q;
    vector<int> dis(n + 1, -1);
    for(int i : tmp){
        q.push(i);
        dis[i] = 0;
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i : g[now]){
            if(dis[i] != -1) continue;
            dis[i] = dis[now] + 1;
            q.push(i);
        }
    }

    int mx = -1;
    for(int i = 1; i <= n; i++){
        if(i == a || i == b) continue;
        if(mx == -1 || dis[i] > dis[mx]) mx = i;
    }

    cout << fv + dis[mx] << "\n";
    cout << a << " " << b << " " << mx << "\n";

    return 0;
}