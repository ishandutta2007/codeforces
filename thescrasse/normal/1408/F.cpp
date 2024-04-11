#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, p2;
vector<array<ll, 2>> sl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    k = 1;
    while (2 * k <= n) k *= 2;
    for (p2 = 2; p2 <= k; p2 *= 2) {
        for (i = 0; i < k; i++) {
            if ((i % p2) < (p2 / 2)) sl.pb({i + 1, i + p2 / 2 + 1});
        }
    }

    for (p2 = 2; p2 <= k; p2 *= 2) {
        for (i = 0; i < k; i++) {
            if ((i % p2) < (p2 / 2)) sl.pb({i + n - k + 1, i + p2 / 2 + n - k + 1});
        }
    }

    cout << sl.size() << nl;
    for (auto u : sl) cout << u[0] << ' ' << u[1] << nl;

    return 0;
}