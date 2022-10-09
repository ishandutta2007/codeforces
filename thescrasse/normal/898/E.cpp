#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], ty[2], c0;
vector<ll> fx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; ty[0] = 0; ty[1] = 0; c0 = 0;
    for (i = 0; i < n; i++) {
        cin >> a[i]; k = sqrt(a[i]);
        if (a[i] == k * k) {
            ty[1]++;
            if (a[i] != 0) c0++;
        } else {
            ty[0]++;
            fx.pb(min(a[i] - k * k, (k + 1) * (k + 1) - a[i]));
        }
    }

    sort(fx.begin(), fx.end());

    res = 0;
    if (ty[1] > n / 2) {
        k = ty[1] - (n / 2);
        if (c0 >= k) cout << k;
        else cout << c0 + 2 * (k - c0);
    } else {
        m = n / 2 - ty[1];
        for (i = 0; i < m; i++) res += fx[i];
        cout << res;
    }

    return 0;
}