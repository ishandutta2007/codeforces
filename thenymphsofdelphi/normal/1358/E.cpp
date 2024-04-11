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

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 5e5 + 5;

int n, m;
int a[N];
int x;

ll b[N], c[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n; m = (n + 1) / 2;
    ForE(i, 1, m){
        cin >> a[i];
    }
    cin >> x;
    ForE(i, 1, m){
        b[i] = b[i - 1] + a[i];
    }
    ForE(i, 1, m){
        c[i] = min(c[i - 1], (ll)i * x - b[i]);
    }
    ForE(k, m, n){
        if (k * 2 <= n){
            continue;
        }
        if (c[n - k] > -b[m] - (ll)(k - m) * x){
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
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