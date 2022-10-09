// 1195E
// OpenStreetMap

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 3010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn][3], x, y, z;
deque<ll> dq;

void dins(ll x) {
    while (!dq.empty() && x < dq.front()) dq.pop_front();
    dq.push_front(x);
}

void ddel(ll x) {
    if (!dq.empty() && dq.back() == x) dq.pop_back();
}

ll dexec(ll n, ll m, ll p) {
    ll res = 0;
    for (i = 0; i < n; i++) {
        dq.clear();
        for (j = 0; j < p; j++) {
            x = mt[i][j][0]; dins(x);
        }
        mt[i][p - 1][1] = dq.back();
        res += mt[i][p - 1][1];

        for (j = p; j < m; j++) {
            x = mt[i][j][0]; dins(x);
            x = mt[i][j - p][0]; ddel(x);
            mt[i][j][1] = dq.back();
            res += mt[i][j][1];
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> a >> b;
    cin >> mt[0][0][0] >> x >> y >> z;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i + j == 0) continue;
            if (j == 0) mt[i][j][0] = mt[i - 1][m - 1][0] * x + y;
            else mt[i][j][0] = mt[i][j - 1][0] * x + y;
            mt[i][j][0] %= z;
        }
    }

    dexec(n, m, b);

    for (i = 0; i < n; i++) {
        for (j = b - 1; j < m; j++) {
            mt[j - b + 1][i][0] = mt[i][j][1];
        }
    }

    /* for (i = 0; i < m - b + 1; i++) {
        for (j = 0; j < n; j++) {
            cout << mt[i][j][0] << ' ';
        }
        cout << nl;
    } */

    cout << dexec(m - b + 1, n, a);

    return 0;
}