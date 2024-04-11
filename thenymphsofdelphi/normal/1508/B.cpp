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

const int N = 1e5 + 5;

ll pw2(int n){
    if (n <= 60){
        return (1ll << n);
    }
    return (1ll << 61);
}

void solve(int n, ll k, int offset){
    if (n <= 0){
        cout << endl;
        return;
    }
    FordE(i, n - 2, 0){
        if (pw2(i) >= k){
            FordE(j, n - i - 1, 1){
                cout << j + offset << ' ';
            }
            solve(i + 1, k, offset + n - i - 1);
            return;
        }
        k -= pw2(i);
    }
    FordE(i, n, 1){
        cout << i + offset << ' ';
    }
    cout << endl;
    return;
}

int n; ll k;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> k;
    if (n <= 60 and k > (1ll << (n - 1))){
        cout << -1 << endl;
        continue;
    }
    solve(n, k, 0);
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