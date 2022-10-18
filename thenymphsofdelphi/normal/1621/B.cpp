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

const int N = 2e5 + 5, inf = 1e9 + 7;

int n;
map <pii, int> mpp;
map <int, int> mppl, mppr;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    mpp.clear(); mppl.clear(); mppr.clear();
    int L = inf, R = 0;

    cin >> n;
    ForE(i, 1, n){
        int l, r, c; cin >> l >> r >> c;
        L = min(L, l); R = max(R, r);
        if (mpp.count(make_pair(l, r))){
            mpp[make_pair(l, r)] = min(mpp[make_pair(l, r)], c);
        }
        else{
            mpp[make_pair(l, r)] = c;
        }
        if (mppl.count(l)){
            mppl[l] = min(mppl[l], c);
        }
        else{
            mppl[l] = c;
        }
        if (mppr.count(r)){
            mppr[r] = min(mppr[r], c);
        }
        else{
            mppr[r] = c;
        }
        int ans = mppl[L] + mppr[R];
        if (mpp.count(make_pair(L, R))){
            ans = min(ans, mpp[make_pair(L, R)]);
        }
        cout << ans << endl;
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