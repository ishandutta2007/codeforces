#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
vector<ll> eo[2];

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
        for (i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        eo[0].clear(); eo[1].clear();

        for (i = 0; i < 2 * n; i++) {
            eo[a[i] % 2].pb(i + 1);
        }

        for (i = 0; i < n - 1; i++) {
            if (!eo[0].empty() && eo[0].size() >= 2) {
                cout << eo[0].back() << ' ';
                eo[0].pop_back();
                cout << eo[0].back() << nl;
                eo[0].pop_back();
            } else if (!eo[1].empty() && eo[1].size() >= 2) {
                cout << eo[1].back() << ' ';
                eo[1].pop_back();
                cout << eo[1].back() << nl;
                eo[1].pop_back();
            }
        }
    }

    return 0;
}