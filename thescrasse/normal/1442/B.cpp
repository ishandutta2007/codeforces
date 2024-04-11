#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], f[maxn], p;
bool visited[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i]; f[a[i]] = i;
        }
        for (i = 0; i < k; i++) {
            cin >> b[i]; visited[b[i]] = true;
        }

        res = 1;
        for (i = 0; i < k; i++) {
            m = 0; p = f[b[i]];
            // cout << p << nl;
            if (p != 0 && visited[a[p - 1]] == false) m++;
            if (p != n - 1 && visited[a[p + 1]] == false) m++;
            visited[b[i]] = false;
            res *= m; res %= mod;
        }

        cout << res << nl;
        // cout << nl;
    }

    return 0;
}