#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> q;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> mt[i][j];
        }
    }

    while (q--) {
        cin >> b; a = 1;
        while (true) {
            if (mt[a][b] == 1) {
                mt[a][b] = 2; b++;
            } else if (mt[a][b] == 2) {
                if (a == n) {
                    cout << b << ' '; break;
                }
                a++;
            } else if (mt[a][b] == 3) {
                mt[a][b] = 2; b--;
            }
        }
    }
    cout << nl;

    return 0;
}