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

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){ return rando() % (r - l + 1) + l; }

const int N = 1e5 + 5;

int n, x, y;
int a[N], ans[N];
vi pos[N];
bool force[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> x >> y;
    ForE(i, 1, n) cin >> a[i];
    ForE(i, 1, n + 1) pos[i].clear();
    ForE(i, 1, n) pos[a[i]].emplace_back(i);
    int nappear = 0;
    ForE(i, 1, n + 1) if (!isz(pos[i])) nappear = i;
    ForE(i, 1, n) ans[i] = 0;
    ForE(i, 1, n) force[i] = 0;
    priority_queue <pii> pq;
    ForE(i, 1, n + 1) pq.push(make_pair(isz(pos[i]), i));
    ForE(i, 1, x){
        pii t = pq.top(); pq.pop();
        ans[pos[t.se].back()] = t.se;
        force[pos[t.se].back()] = 1;
        pos[t.se].pop_back();
        pq.push(make_pair(isz(pos[t.se]), t.se));
    }
    if (pq.top().fi * 2 - (n - x) > n - y){
        cout << "NO" << endl;
        continue;
    }
    vi b, c;
    ForE(j, 1, pq.top().fi) b.push_back(pq.top().se);
    ForE(i, 1, n + 1) if (i != pq.top().se) ForE(j, 1, isz(pos[i])) b.push_back(i);
    c = b; rotate(c.begin(), c.begin() + (n - x) / 2, c.end());
    int cac = n - y;
    For(i, 0, isz(b)){
        if (b[i] == c[i]){
            cac--;
            ans[pos[b[i]].back()] = nappear;
        }
        else{
            ans[pos[b[i]].back()] = c[i];
        }
        pos[b[i]].pop_back();
    }
    ForE(i, 1, n) if (!force[i] and ans[i] != nappear and cac){
        cac--; ans[i] = nappear;
    }
    cout << "YES" << endl;
    ForE(i, 1, n) cout << ans[i] << ' ';
    cout << endl;
}
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/