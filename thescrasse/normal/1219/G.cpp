#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll s[2][maxn];
vector<ll> mt[510];

ll sumk(ll ty, ll k) {
    ll i, r;
    array<ll, 4> o = {0, 0, 0, 0};
    for (i = 1; i <= n * (ty == 0) + m * (ty == 1); i++) {
        if (s[ty][i] <= o[3]) {
        } else if (s[ty][i] <= o[2]) {
            o[3] = s[ty][i];
        } else if (s[ty][i] <= o[1]) {
            o[3] = o[2]; o[2] = s[ty][i];
        } else if (s[ty][i] <= o[0]) {
            o[3] = o[2]; o[2] = o[1]; o[1] = s[ty][i];
        } else {
            o[3] = o[2]; o[2] = o[1]; o[1] = o[0]; o[0] = s[ty][i];
        }
    }

    r = 0;
    for (i = 0; i < k; i++) r += o[i];
    // cout << "sumk" _ ty _ k _ r << nl;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    if (n > m) {
        for (j = 1; j <= m; j++) mt[j].resize(n + 2);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[j][i];
            }
        }
        swap(n, m);
    } else {
        for (i = 1; i <= n; i++) mt[i].resize(m + 2);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[i][j];
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            s[0][i] += mt[i][j]; s[1][j] += mt[i][j];
        }
    }

    if (n == 1) {
        cout << s[0][1] << nl; return 0;
    } else if (n == 2) {
        cout << s[0][1] + s[0][2] << nl; return 0;
    }

    res = max(sumk(0, 4), sumk(1, 4));

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) s[1][j] -= mt[i][j];
        res = max(res, s[0][i] + sumk(1, 3));
        for (j = 1; j <= m; j++) s[1][j] += mt[i][j];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) s[1][j] -= mt[i][j];
        for (k = i + 1; k <= n; k++) {
            for (j = 1; j <= m; j++) s[1][j] -= mt[k][j];
            res = max(res, s[0][i] + s[0][k] + sumk(1, 2));
            for (j = 1; j <= m; j++) s[1][j] += mt[k][j];
        }
        for (j = 1; j <= m; j++) s[1][j] += mt[i][j];
    }

    for (j = 1; j <= m; j++) {
        for (i = 1; i <= n; i++) s[0][i] -= mt[i][j];
        res = max(res, s[1][j] + sumk(0, 3));
        for (i = 1; i <= n; i++) s[0][i] += mt[i][j];
    }

    cout << res << nl;

    return 0;
}