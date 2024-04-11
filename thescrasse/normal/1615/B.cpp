#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll l, r, ps[20][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i < 20; i++) {
        for (j = 0; j < maxn; j++) {
            if (j != 0) ps[i][j] = ps[i][j - 1];
            if ((j >> i) & 1) ps[i][j]++;
        }
    }

    cin >> t;
    while (t--) {
        cin >> l >> r; res = 0;
        for (i = 0; i < 20; i++) res = max(res, ps[i][r] - ps[i][l - 1]);
        res = r - l + 1 - res;
        cout << res << nl;
    }

    return 0;
}