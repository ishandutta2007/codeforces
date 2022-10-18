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

const int N = 1e5 + 5, M = 2e5 + 5;

int n;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    int k; cin >> k;
    if (k <= 100000){
        cout << 1 << endl << -k << endl;
        return 0;
    }
    a[1] = 1; a[2] = -2;
    if (k % 2 == 0){
        n = 2000;
    }
    else{
        n = 1999;
    }
    k += n;
    k /= 2;
    ForE(i, 3, n){
        a[i] = k / (n - 2);
        if (i - 3 < k % (n - 2)){
            a[i]++;
        }
    }
    cout << n << endl;
    ForE(i, 1, n){
        cout << a[i] << ' ';
    } cout << endl;
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