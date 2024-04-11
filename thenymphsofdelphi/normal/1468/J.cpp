#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 2e5 + 5;

struct Edge{
    int u, v, w;
    
    Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {
        
    }
    
    bool operator< (const Edge& oth) const {
        return w < oth.w;
    }
};

int n, m, k;
Edge edges[N];

void readTest(){
    cin >> n >> m >> k;
    ForE(i, 1, m){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
}

struct disjointSetUnion{
    int par[N];
    
    void reset(){
        memset(par, -1, sizeof(par));
    }
    
    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }
    
    bool merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return 0;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return 1;
    }
} dsu;

ll ans;

void resetTest(){
    dsu.reset();
    ans = 0;
}

void solveTest(){
    sort(edges + 1, edges + 1 + m);
    ForE(i, 1, m){
        if (dsu.merge(edges[i].u, edges[i].v)){
            if (edges[i].w > k){
                ans += edges[i].w - k;
            }
            if (-dsu.par[dsu.root(1)] == n){
                if (edges[i].w > k){
                    cout << ans << endl;
                }
                else{
                    ans = 1e9 + 7;
                    int idx = upper_bound(edges + 1, edges + 1 + m, Edge(0, 0, k)) - edges;
                    if (1 <= idx && idx <= m){
                        ans = min(ans, (ll)edges[idx].w - k);
                    }
                    idx--;
                    if (1 <= idx && idx <= m){
                        ans = min(ans, (ll)k - edges[idx].w);
                    }
                    cout << ans << endl;
                }
                return;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    readTest();
    resetTest();
    solveTest();
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/