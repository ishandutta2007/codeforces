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

mt19937_64 rando(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 5;

ll randval[N];
int n, m;
ll c[N];
ll cac[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
For(i, 1, N){
    randval[i] = rando();
}
int q; cin >> q; while (q--){
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> c[i];
    }
    ForE(i, 1, n){
        cac[i] = 0;
    }
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        cac[v] ^= randval[u];
    }
    map <ll, ll> mpp;
    ForE(i, 1, n){
        if (cac[i]){
            mpp[cac[i]] += c[i];
        }
    }
    ll ans = 0;
    Fora(&v, mpp){
        ans = __gcd(ans, v.se);
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