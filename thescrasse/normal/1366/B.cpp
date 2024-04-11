#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b[110][2], x, l[110], r[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> x >> m;
        b[0][0] = x; b[0][1] = x;
        for (i = 1; i <= m; i++) {
            cin >> l[i] >> r[i];
            if (b[i - 1][0] > r[i] || b[i - 1][1] < l[i]) {
                b[i][0] = b[i - 1][0];
                b[i][1] = b[i - 1][1];
            } else {
                b[i][0] = min(b[i - 1][0], l[i]);
                b[i][1] = max(b[i - 1][1], r[i]);
            }
        }
        cout << b[m][1] - b[m][0] + 1 << endl;
    }

    return 0;
}