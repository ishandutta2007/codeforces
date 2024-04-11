#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 60

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn][maxn], b[maxn][2];
string r[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    r[0] = "Vivek"; r[1] = "Ashish";

    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (i = 0; i <= 50; i++) {
            b[i][0] = 0; b[i][1] = 0;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 1) {
                    b[i][0] = 1; b[j][1] = 1;
                }
            }
        }

        res = INF;
        k = 0;
        for (i = 0; i < n; i++) {
            if (b[i][0] == 0) k++;
        }
        res = min(res, k);

        k = 0;
        for (i = 0; i < m; i++) {
            if (b[i][1] == 0) k++;
        }
        res = min(res, k); res %= 2;

        cout << r[res] << endl;
    }

    return 0;
}