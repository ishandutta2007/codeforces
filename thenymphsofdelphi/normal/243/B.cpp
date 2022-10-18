#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

int n, m, x, y;
vi adj[N];

bool ck[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> x >> y;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    ForE(u, 1, n){
        if (isz(adj[u]) < x + 1){
            continue;
        }
        Fora(v, adj[u]){
            ck[v] = 1;
        }
        int tx = isz(adj[u]);
        Fora(v, adj[u]){
            if (isz(adj[v]) < y + 1){
                continue;
            }
            tx--;
            int ty = 0;
            Fora(tv, adj[v]){
                if (tv == u){
                    continue;
                }
                if (ck[tv]){
                    if (tx > x){
                        tx--; ty++;
                    }
                }
                else{
                    ty++;
                }
                if (ty >= y){
                    break;
                }
            }
            if (ty >= y){
                cout << "YES" << endl;
                cout << u << ' ' << v << endl;
                set <int> sttu, sttv;
                Fora(tu, adj[u]){
                    sttu.emplace(tu);
                }
                sttu.erase(v);
                Fora(tv, adj[v]){
                    if (tv == u){
                        continue;
                    }
                    if (sttu.find(tv) == sttu.end()){
                        sttv.emplace(tv);
                    }
                    else{
                        if (isz(sttu) - 1 >= x){
                            sttu.erase(tv); sttv.emplace(tv);
                        }
                    }
                    if (isz(sttv) >= y){
                        break;
                    }
                }
                while (isz(sttu) > x){
                    sttu.erase(sttu.begin());
                }
                Fora(tu, sttu){
                    cout << tu << ' ';
                } cout << endl;
                Fora(tv, sttv){
                    cout << tv << ' ';
                } cout << endl;
                return 0;
            }
            tx = isz(adj[u]);
        }
        Fora(v, adj[u]){
            ck[v] = 0;
        }
    }
    cout << "NO" << endl;
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