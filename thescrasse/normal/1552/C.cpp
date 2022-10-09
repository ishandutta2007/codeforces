#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 210

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll mx;
bool vis[maxn];

void reset() {
    ll i;
    res = 0;
    for (i = 0; i <= 2 * n - 1; i++) {
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k; reset();
        for (i = 1; i <= k; i++) {
            cin >> a[i] >> b[i]; a[i]--; b[i]--;
            if (a[i] > b[i]) swap(a[i], b[i]);
            vis[a[i]] = true; vis[b[i]] = true;
        }

        for (i = 1; i <= k; i++) {
            m = 0;
            for (j = a[i] + 1; j <= b[i] - 1; j++) {
                if (!vis[j]) m++;
            }
            mx = m;

            m = 0;
            for (j = b[i] + 1; j <= a[i] + 2 * n - 1; j++) {
                if (!vis[j % (2 * n)]) m++;
            }
            // cout << "i, mx, m = " << i _ mx _ m << nl;
            mx = min(mx, m);

            res += mx;
        }

        for (i = 1; i <= k; i++) {
            for (j = i + 1; j <= k; j++) {
                if (a[i] <= a[j] && a[j] <= b[i] && b[i] <= b[j]) res++;
                if (a[j] <= a[i] && a[i] <= b[j] && b[j] <= b[i]) res++;
            }
        }

        res += (((n - k) * (n - k - 1)) / 2);
        cout << res << nl;
    }

    return 0;
}