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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }

        if (n % 2) {
            cout << 1 << nl; continue;
        }

        sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
        cout << (a[n / 2 + 1] - a[n / 2] + 1) * (b[n / 2 + 1] - b[n / 2] + 1) << nl;
    }

    return 0;
}