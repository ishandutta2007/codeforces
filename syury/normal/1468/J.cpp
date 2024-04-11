//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;

struct Edge{
    int v, u, c;
    bool operator < (const Edge & e)const{
        return c < e.c;
    }
};

struct dsu{
    vector<int> p;
    dsu(int n):p(n){
        iota(all(p), 0);
    }
    int get(int v){
        return v == p[v] ? v : p[v] = get(p[v]);
    }
    bool unite(int v, int u){
        v = get(v);
        u = get(u);
        if(v == u)
            return false;
        p[v] = u;
        return true;
    }
};

int n, m, k;
Edge ed[N];
Edge e[N];
int sz = 0;
int cntedge = 0;
ll maxedge = 0, sumedge = 0;

void kruskal(){
    sort(e, e + sz);
    dsu d(n);
    cntedge = maxedge = sumedge = 0;
    for(int i = 0; i < sz; i++){
        if(d.unite(e[i].v, e[i].u)){
            ++cntedge;
            maxedge = max(maxedge, (ll)e[i].c);
            sumedge += e[i].c;
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> ed[i].v >> ed[i].u >> ed[i].c;
        --ed[i].v; --ed[i].u;
    }
    ll ans = (ll)1e18;
    sz = 0;
    for(int i = 0; i < m; i++){
        if(ed[i].c <= k){
            e[sz++] = Edge{ed[i].v, ed[i].u, k - ed[i].c};
        }
    }
    kruskal();
    if(cntedge == n - 1)
        ans = e[0].c;
    sz = 0;
    for(int i = 0; i < m; i++){
        e[sz++] = Edge{ed[i].v, ed[i].u, max(0, ed[i].c - k)};
    }
    kruskal();
    if(sumedge != 0)
        ans = min(ans, sumedge);
    else{
        for(int i = 0; i < sz; i++)
            if(e[i].c != 0)
                ans = min(ans, (ll)e[i].c);
    }
    cout << ans << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}