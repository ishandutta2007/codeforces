#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

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
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        flag[0] = 0; res = n;
        for (i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                flag[0] = 1;
            }
            else if (a[i] > a[i + 1] && flag[0] == 1) {
                res = n - 1 - (i + 1) + 1; break;
            }
        }

        res = n - res;
        cout << res << nl;
    }

    return 0;
}