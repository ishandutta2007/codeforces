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

int n;
string s, t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> s >> t;
    bool ck = 0; int l = 0, r = n - 1; vi vans;
    FordE(i, n - 1, 0){
        if (ck){
            if (s[r] != t[i]){
                vans.emplace_back(1);
            }
            vans.emplace_back(i + 1);
            r--; ck = 0;
        }
        else{
            if (s[l] == t[i]){
                vans.emplace_back(1);
            }
            vans.emplace_back(i + 1);
            l++; ck = 1;
        }
    }
    cout << isz(vans) << ' ';
    Fora(&v, vans) cout << v << ' ';
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