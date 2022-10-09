#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x, y, p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> p;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    // for (i = 0; i < n; i++) a[i] -= i;
    // sort(a, a + n);
    x = 0; y = INF;
    for (i = 0; i < n; i++) {
        x = max(x, a[i] - i);
    }
    for (i = 0; i < n - p + 1; i++) {
        y = min(y, a[i + p - 1] - i - 1);
    }

    cout << max((ll)0, y - x + 1) << nl;
    for (i = x; i <= y; i++) cout << i << ' ';

    return 0;
}