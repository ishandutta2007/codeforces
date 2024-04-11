#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, p[maxn], s[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; p[0] = INF; s[n + 1] = INF;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) p[i] = min(p[i - 1], a[i]);
        for (i = n; i >= 1; i--) s[i] = min(s[i + 1], a[i]);

        flag[0] = 0;
        for (i = 1; i <= n; i++) {
            if (p[i] < a[i] && s[i] < a[i]) {
                cout << "YES" << nl;
                for (j = 1; j <= i - 1; j++) {
                    if (a[j] == p[i]) {
                        cout << j << ' '; break;
                    }
                }
                cout << i << ' ';
                for (j = i + 1; j <= n; j++) {
                    if (a[j] == s[i]) {
                        cout << j << nl; break;
                    }
                }
                flag[0] = 1; break;
            }
        }

        if (flag[0] == 0) {
            cout << "NO" << nl;
        }
    }

    return 0;
}