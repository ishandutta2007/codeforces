#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 310

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn], x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k % n == 0) cout << 0;
        else cout << 2;
        cout << nl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) mt[i][j] = 0;
        }

        for (i = 0; i < k; i++) {
            x = i / n;
            mt[(i % n)][(i + x) % n] = 1;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << mt[i][j];
            }
            cout << nl;
        }
    }

    return 0;
}