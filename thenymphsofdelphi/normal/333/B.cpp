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

const int N = 1e3 + 5;

int n, m;
bool ckr[N], ckc[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int x, y; cin >> x >> y;
        ckr[x] = 1; ckc[y] = 1;
    }

    int ans = 0;
    ForE(i, 2, n / 2){
        int tans = 0;
        For(msk, 0, 81){
            int rup = (msk / 27) % 3, rdown = (msk / 9) % 3, cleft = (msk / 3) % 3, cright = (msk / 1) % 3;
            if ((rup and ckr[i]) or (rdown and ckr[n - i + 1]) or (cleft and ckc[i]) or (cright and ckc[n - i + 1])){
                continue;
            }
            if ((rup == 1 and cleft == 1) or (rup == 1 and cright == 2) or (rup == 2 and cleft == 2) or (rup == 2 and cright == 1) or (rdown == 1 and cleft == 2) or (rdown == 1 and cright == 1) or (rdown == 2 and cleft == 1) or (rdown == 2 and cright == 2)){
                continue;
            }
            tans = max(tans, (rup ? 1 : 0) + (rdown ? 1 : 0) + (cleft ? 1 : 0) + (cright ? 1 : 0));
        }
        ans += tans;
    }
    if (n % 2 == 1){
        if (!ckr[n / 2 + 1] or !ckc[n / 2 + 1]){
            ans++;
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