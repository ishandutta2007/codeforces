#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 5;

ll a[maxn];

signed main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif // DEBUG
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll r = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll r1 = (a[i] + k - 1) / k;
        if (i) {
            int d = min(r1 * k - a[i], a[i - 1]);
            a[i - 1] -= d;
        }
        r += r1;
    }
    cout << r;
    return 0;
}