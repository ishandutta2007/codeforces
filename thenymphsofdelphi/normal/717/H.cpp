#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")

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

const int N = 5e4 + 5, M = 1e5 + 5, K = 1e6 + 5;

int n, m, t;
pii hate[M];
vi a[N];

int ans1[N], ans2[K];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        cin >> hate[i].fi >> hate[i].se;
    }
    ForE(i, 1, n){
        int x; cin >> x;
        ForE(j, 1, x){
            int y; cin >> y; t = max(t, y);
            a[i].push_back(y);
        }
    }
    while (1){
        ForE(i, 1, n){
            ans1[i] = a[i][randt(0, isz(a[i]) - 1)];
        }
        ForE(i, 1, t){
            ans2[i] = randt(1, 2);
        }
        int cnt = 0;
        ForE(i, 1, m){
            if (ans2[ans1[hate[i].fi]] != ans2[ans1[hate[i].se]]){
                cnt++;
            }
        }
        if (cnt * 2 >= m){
            ForE(i, 1, n){
                cout << ans1[i] << ' ';
            } cout << endl;
            ForE(i, 1, t){
                cout << ans2[i] << ' ';
            } cout << endl;
            return 0;
        }
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