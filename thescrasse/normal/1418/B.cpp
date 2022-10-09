#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
vector<ll> x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; x.clear(); y.clear();
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] == 0) {
                x.pb(-a[i]); y.pb(i);
            }
        }

        sort(x.begin(), x.end());
        for (i = 0; i < x.size(); i++) {
            a[y[i]] = -x[i];
        }

        for (i = 0; i < n; i++) cout << a[i] << ' ';
        cout << nl;
    }

    return 0;
}