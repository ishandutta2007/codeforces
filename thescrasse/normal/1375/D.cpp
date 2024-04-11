#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, cnt;
bool visited[maxn], fxd[maxn];
vector<ll> r;

ll mex() {
    for (i = 0; i <= n; i++) visited[i] = false;
    for (i = 1; i <= n; i++) visited[a[i]] = true;
    for (i = 0; i <= n; i++) {
        if (!visited[i]) return i;
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
        r.clear();
        cin >> n; fxd[0] = true; k = 0; cnt = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == i - 1) {
                fxd[i] = true; k++;
            } else {
                fxd[i] = false;
            }
        }

        while (k != n) {
            m = mex();
            if (m == n) {
                for (i = 1; i <= n; i++) {
                    if (fxd[i] == false) {
                        a[i] = n; break;
                    }
                }
            } else {
                i = m + 1;
                if (!fxd[i]) {
                    fxd[i] = true; k++;
                }
                a[i] = i - 1;
            }
            r.pb(i); cnt++;
        }

        cout << cnt << nl;
        for (auto u : r) cout << u << ' ';
        cout << nl;
    }

    return 0;
}