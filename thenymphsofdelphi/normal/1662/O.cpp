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

const int R = 22, C = 360;

int q;
bool wallcir[R][C];
bool wallstr[R][C];

bool vis[R][C];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    memset(wallcir, 0, sizeof(wallcir));
    memset(wallstr, 0, sizeof(wallstr));

    cin >> q;
    while (q--){
        char type; cin >> type;
        if (type == 'C'){
            int r, ang1, ang2; cin >> r >> ang1 >> ang2;
            while (ang1 != ang2){
                wallcir[r][ang1] = 1;
                ang1++; if (ang1 == C) ang1 = 0;
            }
        }
        else{
            int r1, r2, ang; cin >> r1 >> r2 >> ang;
            ForE(r, r1 + 1, r2){
                wallstr[r][ang] = 1;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    queue <pii> qu;
    For(ang, 0, C){
        vis[1][ang] = 1;
        qu.emplace(1, ang);
    }
    bool ans = 0;
    while (!qu.empty()){
        int r, ang; tie(r, ang) = qu.front(); qu.pop();
        if (r == R - 1){
            ans = 1;
            break;
        }
        if (r > 1 and !wallcir[r - 1][ang] and !vis[r - 1][ang]){
            vis[r - 1][ang] = 1;
            qu.emplace(r - 1, ang);
        }
        if (!wallcir[r][ang] and !vis[r + 1][ang]){
            vis[r + 1][ang] = 1;
            qu.emplace(r + 1, ang);
        }
        int ang1;
        ang1 = ang - 1; if (ang1 == -1) ang1 = C - 1;
        if (!wallstr[r][ang] and !vis[r][ang1]){
            vis[r][ang1] = 1;
            qu.emplace(r, ang1);
        }
        ang1 = ang + 1; if (ang1 == C) ang1 = 0;
        if (!wallstr[r][ang1] and !vis[r][ang1]){
            vis[r][ang1] = 1;
            qu.emplace(r, ang1);
        }
    }
    if (ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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