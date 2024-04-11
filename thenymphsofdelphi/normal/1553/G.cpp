#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

const int N = 1e5 + 5e4 + 5, Q = 3e5 + 5, MX = 1e6 + 5;

struct disjoint_set{
    int n;
    vector<int> p;
    disjoint_set(int n): n(n), p(n, -1){ }
    // Amortized O(alpha(n))
    int root(int u){
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
    // Amortized O(alpha(n))
    bool share(int a, int b){
        return root(a) == root(b);
    }
    // Amortized O(alpha(n))
    int size(int u){
        return -p[root(u)];
    }
    // Amortized O(alpha(n))
    bool merge(int u, int v){
        u = root(u), v = root(v);
        if(u == v) return false;
        if(p[u] > p[v]) swap(u, v);
        p[u] += p[v], p[v] = u;
        return true;
    }
    // Amortized O(alpha(n))
    bool merge(int u, int v, auto act){
        u = root(u), v = root(v);
        if(u == v) return false;
        if(p[u] > p[v]) swap(u, v);
        p[u] += p[v], p[v] = u;
        act(u, v);
        return true;
    }
    // O(n)
    void clear(){
        fill(p.begin(), p.end(), -1);
    }
    // O(n)
    vector<vector<int>> group_up(){
        vector<vector<int>> g(n);
        for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
        g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
        return g;
    }
};

int lpf[MX];
vi vprime;

void sieve(){
    For(i, 2, MX){
        if (lpf[i] == 0){
            lpf[i] = i;
            vprime.emplace_back(i);
        }
        for (int j = 0; j < isz(vprime) and vprime[j] <= lpf[i] and i * vprime[j] < MX; j++){
            lpf[i * vprime[j]] = vprime[j];
        }
    }
}

int n, q;
int a[N];

vi vdiv[MX];
vi vidx[MX];

set <pii> stt;

disjoint_set dsu(N + 1);

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    sieve();

    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }

    For(i, 1, MX){
        int x = i;
        while (x != 1){
            int p = lpf[x];
            while (lpf[x] == p){
                x /= p;
            }
            vdiv[i].emplace_back(p);
        }
    }
    ForE(i, 1, n){
        Fora(p, vdiv[a[i]]){
            vidx[p].emplace_back(i);
        }
    }

    For(i, 1, MX){
        For(j, 1, isz(vidx[i])){
            dsu.merge(vidx[i][j - 1], vidx[i][j]);
        }
    }

    ForE(i, 1, n){
        vi vvdiv = vdiv[a[i]]; vvdiv.insert(vvdiv.end(), bend(vdiv[a[i] + 1]));
        Fora(p1, vvdiv){
            Fora(p2, vvdiv){
                if (vidx[p1].empty() or vidx[p2].empty()){
                    continue;
                }
                int u = dsu.root(vidx[p1][0]), v = dsu.root(vidx[p2][0]);
                if (u == v){
                    continue;
                }
                if (u > v){
                    swap(u, v);
                }
                stt.emplace(u, v);
            }
        }
    }

    while (q--){
        int i, j; cin >> i >> j;
        if (dsu.share(i, j)){
            cout << 0 << endl;
            continue;
        }
        int ans = 2;
        Fora(p1, vdiv[a[i]]){
            Fora(p2, vdiv[a[j]]){
                int u = dsu.root(vidx[p1][0]), v = dsu.root(vidx[p2][0]);
                if (u > v){
                    swap(u, v);
                }
                if (stt.find(make_pair(u, v)) != stt.end()){
                    ans = 1;
                    break;
                }
            }
            if (ans != 2){
                break;
            }
        }
        cout << ans << endl;
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