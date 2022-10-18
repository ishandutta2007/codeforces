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

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values; // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), gr(2*n) {}

    int addVar() { // (optional)
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }

    void either(int f, int j) {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        gr[f].push_back(j^1);
        gr[j].push_back(f^1);
    }
    void setValue(int x) { either(x, x); }

    void atMostOne(const vi& li) { // (optional)
        if (isz(li) <= 1) return;
        int cur = ~li[0];
        For(i,2,isz(li)) {
            int next = addVar();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    }

    vi val, comp, z; int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        for(int e : gr[i]) if (!comp[e])
            low = min(low, val[e] ?: dfs(e));
        if (low == val[i]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if (values[x>>1] == -1)
                values[x>>1] = x&1;
        } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2*N, 0); comp = val;
        For(i,0,2*N) if (!comp[i]) dfs(i);
        For(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
        return 1;
    }
};

const int N = 5e4 + 5, inf = 1e9 + 7;

struct Edge{
    int u, v, c, t;

    Edge(int u = 0, int v = 0, int c = 0, int t = 0): u(u), v(v), c(c), t(t){

    }
};

bool operator<(const Edge& lhs, const Edge& rhs){
    return lhs.t < rhs.t;
}

int n, m;
Edge edges[N];
vi adj[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        cin >> edges[i].u >> edges[i].v >> edges[i].c >> edges[i].t;
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }
    ForE(i, 1, n){
        unordered_map <int, int> mpp;
        Fora(&j, adj[i]){
            mpp[edges[j].c]++;
        }
        Fora(&elem, mpp){
            if (elem.se > 2){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    int l = 0, r = inf;
    while (l < r){
        int mid = (l + r) >> 1;
        TwoSat cac(m + 1);
        ForE(i, 1, n){
            unordered_map <int, vi> mpp;
            Fora(&j, adj[i]){
                mpp[edges[j].c].push_back(j);
            }
            Fora(&elem, mpp){
                if (isz(elem.se) == 2){
                    cac.either(elem.se[0], elem.se[1]);
                }
            }
        }
        ForE(i, 1, n){
            cac.atMostOne(adj[i]);
        }
        ForE(i, 1, m){
            if (edges[i].t > mid){
                cac.setValue(~i);
            }
        }
        if (cac.solve()){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if (l == inf){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << l << ' ';
    TwoSat cac(m + 1);
    ForE(i, 1, n){
        unordered_map <int, vi> mpp;
        Fora(&j, adj[i]){
            mpp[edges[j].c].push_back(j);
        }
        Fora(&elem, mpp){
            if (isz(elem.se) == 2){
                cac.either(elem.se[0], elem.se[1]);
            }
        }
    }
    ForE(i, 1, n){
        cac.atMostOne(adj[i]);
    }
    ForE(i, 1, m){
        if (edges[i].t > l){
            cac.setValue(~i);
        }
    }
    cac.solve();
    vi vans;
    ForE(i, 1, m){
        if (cac.values[i]){
            vans.push_back(i);
        }
    }
    cout << isz(vans) << endl;
    Fora(&v, vans){
        cout << v << ' ';
    } cout << endl;
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