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

const int N = 2e5 + 5;

int n;
pair <pii, int> a[N];

int b[N], c[N];
bool ans[N];
string sans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi.fi;
    }
    ForE(i, 1, n){
        cin >> a[i].fi.se;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    b[0] = 0;
    ForE(i, 1, n){
        b[i] = max(b[i - 1], a[i].fi.se);
    }
    c[n + 1] = INT_MAX;
    FordE(i, n, 1){
        c[i] = min(c[i + 1], a[i].fi.se);
    }
    ForE(i, 1, n){
        ans[i] = 0;
    }
    ans[n] = 1;
    FordE(i, n - 1, 1){
        int idx = lower_bound(c + 1, c + n + 1, b[i]) - c - 1;
        if (idx > i){
            ans[i] = ans[idx];
        }
    }
    sans.resize(n);
    ForE(i, 1, n){
        sans[a[i].se - 1] = ans[i] + '0';
    }
    cout << sans << endl;
}
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