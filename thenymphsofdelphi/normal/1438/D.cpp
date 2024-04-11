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

int n, x;
int a[N];

vvi vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        x ^= a[i];
    }
    if (n % 2 == 0 && x != 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int i;
    for (i = n - 2; i >= 1; i -= 2){
        vans.push_back({i, i + 1, i + 2});
    }
    i += 2;
    for (int j = i + 2; j <= n; j += 2){
        vans.push_back({i, j - 1, j});
    }
    cout << isz(vans) << endl;
    Fora(&u, vans){
        Fora(&v, u){
            cout << v << ' ';
        } cout << endl;
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