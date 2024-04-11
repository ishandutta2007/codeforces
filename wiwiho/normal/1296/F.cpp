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
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<int>> g;
vector<int> d, pr;

void dfs(int now, int p){
    d[now] = d[p] + 1;
    pr[now] = p;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);
    vector<pii> e(n - 1);
    for(int i = 0; i < n - 1;i ++){
        int u, v;
        cin >> u >> v;
        e[i] = mp(u, v);
        g[u].eb(v);
        g[v].eb(u);
    }

    d.resize(n + 1);
    pr.resize(n + 1);
    dfs(1, 1);

    int m;
    cin >> m;
    vector<pair<pii, int>> q(m);
    //printv(d, cerr);

    vector<int> ans(n + 1, 1);

    for(int i = 0; i < m; i++){
        cin >> q[i].F.F >> q[i].F.S >> q[i].S;

        int u = q[i].F.F, v = q[i].F.S, mn = q[i].S;
        if(d[u] < d[v]) swap(u, v);
        while(d[u] > d[v]){
            ans[u] = max(ans[u], mn);
            u = pr[u];
        }

        while(u != v){
            //cerr << u << " " << v << "\n";
            ans[u] = max(ans[u], mn);
            ans[v] = max(ans[v], mn);
            u = pr[u];
            v = pr[v];
        }
    }

    for(int i = 0; i < m; i++){
        int u = q[i].F.F, v = q[i].F.S, mn = q[i].S;
        int t = MAX;
        if(d[u] < d[v]) swap(u, v);
        while(d[u] > d[v]){
            t = min(ans[u], t);
            u = pr[u];
        }

        while(u != v){
            t = min(ans[u], t);
            t = min(ans[v], t);
            u = pr[u];
            v = pr[v];
        }

        if(t != mn){
            cout << "-1\n";
            return 0;
        }
    }

    vector<int> a(n - 1);
    for(int i = 0; i < n - 1; i++){
        int u = e[i].F, v = e[i].S;
        if(d[u] < d[v]) swap(u, v);
        a[i] = ans[u];
    }

    printv(a, cout);

    return 0;
}