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

const int N = 2e5 + 5, M = 1e6 + 5, mod = 1e9 + 7;

int lpf[M];
vi vprime;

void sieve(){
    For(i, 2, M){
        if (lpf[i] == 0){
            lpf[i] = i;
            vprime.emplace_back(i);
        }
        for (int j = 0; j < isz(vprime) and vprime[j] <= lpf[i] and vprime[j] * i < M; j++){
            lpf[vprime[j] * i] = vprime[j];
        }
    }
}

int n, k;
int a[N];

ll ans;
int b[N];
int l[N], r[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
sieve();
int tests; cin >> tests; while (tests--){
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
        if (a[i] != 1 and lpf[a[i]] != a[i]){
            a[i] = 0;
        }
        else if (a[i] != 1){
            a[i] = -1;
        }
    }
    ans = 0;

    ForE(j, 1, k){
        int m = 0;
        for (int i = j; i <= n; i += k){
            b[++m] = a[i];
        }
        int tl = 0;
        ForE(i, 1, m){
            l[i] = tl;
            if (b[i] != 1){
                tl = i;
            }
        }
        int tr = m + 1;
        FordE(i, m, 1){
            r[i] = tr;
            if (b[i] != 1){
                tr = i;
            }
        }
        ForE(i, 1, m){
            if (b[i] == -1){
                ans += (ll)(i - l[i]) * (r[i] - i) - 1;
            }
        }
    }
    cout << ans << endl;
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