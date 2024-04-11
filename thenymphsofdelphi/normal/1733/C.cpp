#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    int n; cin >> n;
    vi a(n);
    For(i, 0, n){
        cin >> a[i];
    }

    vpii vans;
    int j = 0;
    For(i, 1, n){
        if (a[i] % 2 == a[0] % 2){
            j = i;
        }
    }
    For(i, 0, j){
        if (a[i] % 2 == a[j] % 2){
            vans.emplace_back(i, j);
        }
    }
    For(i, 0, n){
        if (a[i] % 2 != a[0] % 2){
            vans.emplace_back(0, i);
        }
    }
    cout << isz(vans) << endl;
    Fora(elem, vans){
        cout << elem.fi + 1 << ' ' << elem.se + 1 << endl;
    }
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