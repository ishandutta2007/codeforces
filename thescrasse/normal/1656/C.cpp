#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

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
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);
        flag[0] = 0; flag[1] = 0;
        for (i = 2; i <= n; i++) {
            if (a[i] == a[i - 1] + 1) flag[0] = 1;
        }
        for (i = 1; i <= n; i++) {
            if (a[i] == 1) flag[1] = 1;
        }

        if (flag[0] == 1 && flag[1] == 1) cout << "NO" << nl;
        else cout << "YES" << nl;
    }

    return 0;
}