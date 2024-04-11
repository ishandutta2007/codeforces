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

int n;
ll a[N], b[N];
ll k;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 2, n){
        b[i] = a[i] - a[i - 1];
    }
    k = a[1];
    ForE(i, 2, n){
        k += max(0ll, b[i]);
    }
    if (k >= 0){
        cout << (k + 1) / 2 << endl;
    }
    else{
        cout << k / 2 << endl;
    }
    int q; cin >> q; while (q--){
        int l, r, x; cin >> l >> r >> x;
        if (l != 1){
            k -= max(0ll, b[l]);
            b[l] += x;
            k += max(0ll, b[l]);
        }
        else{
            k += x;
            a[1] += x;
        }
        if (r + 1 != n + 1){
            k -= max(0ll, b[r + 1]);
            b[r + 1] -= x;
            k += max(0ll, b[r + 1]);
        }
        if (k >= 0){
            cout << (k + 1) / 2 << endl;
        }
        else{
            cout << k / 2 << endl;
        }
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/