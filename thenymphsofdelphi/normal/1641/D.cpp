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

const int N = 1e5 + 5, M = 5;

int n, m;
int a[N][M], w[N];

vvi b[M + 1];
gp_hash_table <ll, vi> mpp[M + 1];

ll cal(int val){
    ll ans = 0;
    ForE(popcnt, 0, m){
        ll tans = 0;
        Fora(&c, b[popcnt]){
            int r = isz(c) - 1;
            For(l, 0, isz(c)){
                while (r >= 0 and c[l] + c[r] > val){
                    r--;
                }
                tans += r + 1;
            }
        }
        if (popcnt & 1){
            ans -= tans;
        }
        else{
            ans += tans;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        For(j, 0, m){
            cin >> a[i][j];
        }
        sort(a[i], a[i] + m);
        cin >> w[i];
    }

    {
        b[0].resize(1);
        ForE(i, 1, n){
            b[0][0].emplace_back(w[i]);
        }
        sort(bend(b[0][0]));
    }
    For(msk, 1, (1 << m)){
        int popcnt = __builtin_popcount(msk);
        ForE(i, 1, n){
            ll hsh = 0;
            For(j, 0, m){
                if (msk & (1 << j)){
                    hsh = hsh * 1000000007 + a[i][j];
                }
            }
            mpp[popcnt][hsh].emplace_back(w[i]);
        }
    }
    ForE(popcnt, 1, m){
        Fora(&elem, mpp[popcnt]){
            b[popcnt].emplace_back(elem.se);
            sort(bend(b[popcnt].back()));
        }
    }

    ll cntall = cal(2e9);
    if (cntall == 0){
        cout << -1 << endl;
        return 0;
    }
    int lo = 1, hi = 2e9;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;

        if (cal(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << lo << endl;
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