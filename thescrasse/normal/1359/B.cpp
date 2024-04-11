#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, x, y;
char mt[110][1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        res = 0;
        for (i = 0; i < n; i++) {
            k = 0;
            for (j = 0; j < m; j++) {
                cin >> mt[i][j];
                if (mt[i][j] == '.') {
                    k++;
                }
                if (mt[i][j] == '*' || j == m - 1) {
                    if (k % 2 == 1) {
                        res += x; k--;
                    }
                    res += min(x * k, y * (k / 2));
                    k = 0;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}