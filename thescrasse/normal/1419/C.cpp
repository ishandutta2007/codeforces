#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k; s = 0; flag[0] = 1; flag[1] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i]; s += a[i];
            if (k != a[i]) flag[0] = 0;
            else flag[1] = 1;
        }

        if (flag[0] == 1) cout << 0 << nl;
        else if (s / n == k && s % n == 0) cout << 1 << nl;
        else if (flag[1] == 1) cout << 1 << nl;
        else cout << 2 << nl;
    }

    return 0;
}