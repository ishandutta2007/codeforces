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

const int N = 1e6 + 5;

int n; ll ans;
ll a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    auto t = chrono::steady_clock::now().time_since_epoch().count();
    while (chrono::steady_clock::now().time_since_epoch().count() - t <= 3500000000ll){
        int idx = randt(1, n);
        unordered_map <ll, int> mpp;
        ForE(i, 1, n){
            mpp[__gcd(a[i], a[idx])]++;
        }
        Fora(&x, mpp){
            int tans = 0;
            Fora(&y, mpp){
                if (!(y.fi % x.fi)){
                    tans += y.se;
                }
            }
            if (tans * 2 >= n){
                ans = max(ans, x.fi);
            }
        }
    }
    cout << ans << endl;
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