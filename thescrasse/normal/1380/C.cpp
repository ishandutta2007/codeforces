#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x, l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n); reverse(a, a + n);

        res = 0; k = 0; l = 0;
        for (i = 0; i < n; i++) {
            if (k >= x) {
                k = 0; l = 0; res++;
            }
            l++; k = l * a[i];
        }

        if (k >= x) res++;

        cout << res << nl;
    }

    return 0;
}