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

const int N = 5e3 + 5;

int n;
int a[N];

ll costl[N], costr[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ll ans = LLONG_MAX;
    ForE(i, 1, n){
        ll x = 0;
        FordE(j, i - 1, 1){
            ll tx = x / a[j];
            while (tx * a[j] >= x){
                tx--;
            }
            while ((tx + 1) * a[j] < x){
                tx++;
            }
            costl[i] -= tx;
            x = tx * a[j];
        }
        x = 0;
        ForE(j, i + 1, n){
            ll tx = x / a[j];
            while (tx * a[j] <= x){
                tx++;
            }
            while ((tx - 1) * a[j] > x){
                tx--;
            }
            costr[i] += tx;
            x = tx * a[j];
        }
        ans = min(ans, costl[i] + costr[i]);
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