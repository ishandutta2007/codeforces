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

const int N = 1e6 + 5, inf = 1e9 + 7;

int n;
int a[N];

ll ans;
int l[N], r[N], c[N];

inline int prev(int x, int k = 1){
    return ((x - k) % n + n) % n;
}

inline int next(int x, int k = 1){
    return (x + k) % n;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 0, n){
        cin >> a[i];
    }
    int valmx = 0, cntmx = 1, posmx = -1;
    For(i, 0, n){
        if (valmx < a[i]){
            valmx = a[i]; cntmx = 1; posmx = i;
        }
        else if (valmx == a[i]){
            cntmx++;
        }
    }
    rotate(a, a + posmx, a + n);
    a[n] = valmx;

    r[n] = n;
    FordE(i, n - 1, 0){
        r[i] = i + 1;
        while (r[i] < n and a[r[i]] < a[i]){
            r[i] = r[r[i]];
        }
        if (r[i] < n and a[r[i]] == a[i]){
            c[i] = c[r[i]] + 1;
            r[i] = r[r[i]];
        }
    }

    l[0] = 0;
    ForE(i, 1, n){
        l[i] = i - 1;
        while (l[i] > 0 and a[l[i]] < a[i]){
            l[i] = l[l[i]];
        }
        if (l[i] > 0 and a[l[i]] == a[i]){
            l[i] = l[l[i]];
        }
    }

    ans = (ll)cntmx * (cntmx - 1) / 2;
    For(i, 0, n){
        if (a[i] != valmx){
            ans += c[i] + 2;
            if (l[i] == 0 and r[i] == n){
                ans--;
            }
        }
    }
    cout << ans << endl;
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