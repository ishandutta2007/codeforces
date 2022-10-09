#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x, f, c, cr, l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m >> k; x = n % m; f = n / m; c = (n + m - 1) / m; cr = 0;
        for (i = 1; i <= k; i++) {
            for (j = cr; j != (cr + c * x) % n; j = (j + c) % n) {
                cout << c << ' ';
                for (l = j; l != (j + c) % n; l = (l + 1) % n) cout << l + 1 << ' ';
                cout << nl;
            }
            flag[0] = 1;
            for (; j != cr || flag[0] == 1; j = (j + f) % n) {
                flag[0] = 0; flag[1] = 1;
                cout << f << ' ';
                for (l = j; l != (j + f) % n || flag[1] == 1; l = (l + 1) % n) {
                    flag[1] = 0;
                    cout << l + 1 << ' ';
                }
                cout << nl;
            }
            cr = (cr + c * x) % n;
        }
        cout << nl;
    }

    return 0;
}