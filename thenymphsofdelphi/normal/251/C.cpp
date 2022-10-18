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

const int N = 360360, M = 36;

ll L, R; int k;

int nxt[M][N];
pair <ll, ll> dist[M][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> R >> L >> k;

    nxt[0][0] = N - 1;
    dist[0][0] = make_pair(1, 1);
    For(i, 1, N){
        int j = i - 1;
        ForE(x, 2, k){
            j = min(j, i - i % x);
        }
        nxt[0][i] = j;
        dist[0][i] = make_pair(1, i - j);
    }
    For(j, 1, M){
        For(i, 0, N){
            nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
            dist[j][i] = make_pair(dist[j - 1][i].fi + dist[j - 1][nxt[j - 1][i]].fi, dist[j - 1][i].se + dist[j - 1][nxt[j - 1][i]].se);
        }
    }
    int i = R % N;
    ll ans = 0;
    FordE(j, M - 1, 0){
        while (R - dist[j][i].se >= L + 30){
            ans += dist[j][i].fi;
            R -= dist[j][i].se;
            i = nxt[j][i];
        }
    }
    while (R != L){
        ans++;
        ll tR = R - 1;
        ForE(x, 2, k){
            if (R - R % x >= L){
                tR = min(tR, R - R % x);
            }
        }
        R = tR;
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