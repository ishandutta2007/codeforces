#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            mt[i][j] = -1;
        }
    }
    for (i = 1; i <= n; i++) {
        cin >> mt[i][i];
    }

    for (i = 1; i <= n; i++) {
        k = mt[i][i]; x = i; y = i;
        for (j = 1; j <= k - 1; j++) {
            if (mt[x][y - 1] == -1) {
                mt[x][y - 1] = k; y--;
            } else {
                mt[x + 1][y] = k; x++;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (mt[i][j] != -1) cout << mt[i][j] << ' ';
        }
        cout << nl;
    }

    return 0;
}