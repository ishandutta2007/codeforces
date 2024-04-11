#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 10010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
bool vis[maxn];

ll ask(ll x) {
    cout << "?" _ x << nf;
    cin >> x; return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> t;
    while (t--) {
        cin >> n;

        for (i = 1; i <= n; i++) vis[i] = false;

        for (i = 1; i <= n; i++) {
            if (vis[i]) continue;
            k = ask(i);
            while (!vis[k]) {
                vis[k] = true;
                m = ask(i);
                a[k] = m; k = m;
            }
        }

        cout << "!" << ' ';
        for (i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << nf;
    }

    return 0;
}