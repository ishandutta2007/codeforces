#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x, y;
char mt[maxn][maxn];

void jm(ll &x, ll &y) {
    if (x == 1) {
        if (y <= m - 2) {
            y += 2;
        } else {
            x = 3; y = m;
        }
    } else if (x == n) {
        if (y >= 3) {
            y -= 2;
        } else if (n >= 5) {
            x = n - 2; y = 1;
        }
    } else if (y == 1) {
        if (x >= 5) x -= 2;
    } else if (y == m) {
        if (x <= n - 2) {
            x += 2;
        } else {
            x = n; y = m - 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                mt[i][j] = '0';
            }
        }

        x = 1; y = 1;
        for (i = 1; i <= 1000; i++) {
            mt[x][y] = '1';
            jm(x, y);
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << mt[i][j];
            }
            cout << nl;
        }
        cout << nl;
    }

    return 0;
}