#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    cout << 3 * n + 4 << nl;
    cout << 0 << ' ' << 0 << nl;
    cout << 0 << ' ' << 1 << nl;
    for (i = 1; i <= n; i++) {
        cout << i << ' ' << i - 1 << nl;
        cout << i << ' ' << i << nl;
        cout << i << ' ' << i + 1 << nl;
    }
    cout << n + 1 << ' ' << n << nl;
    cout << n + 1 << ' ' << n + 1 << nl;

    return 0;
}