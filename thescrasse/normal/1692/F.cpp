#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll sz;
vector<ll> v;

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
        for (i = 1; i <= n; i++) {
            cin >> a[i]; a[i] %= 10;
        }

        sort(a + 1, a + n + 1); v.clear();

        for (i = 1; i <= n; i++) {
            if (i <= 3 || a[i] != a[i - 3]) v.pb(a[i]);
        }

        sz = v.size(); flag[0] = 0;
        for (i = 0; i < sz; i++) {
            for (j = i + 1; j < sz; j++) {
                for (k = j + 1; k < sz; k++) {
                    if ((v[i] + v[j] + v[k]) % 10 == 3) flag[0] = 1;
                }
            }
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}