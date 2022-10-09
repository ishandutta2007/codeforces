#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], s;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; s = 0;
    for (i = 0; i < n; i++) {
        cin >> a[i]; s += a[i];
    }

    for (i = 0; i < n; i++) {
        b[i] = 2 * s + (2 * i - n + 1) * (n - 1);
        // cout << b[i] << ' ';
        b[i] += n; b[i] /= (2 * n);
    }
    // cout << nl;

    for (i = 0; i < n; i++) cout << b[i] << ' ';
    cout << nl;

    return 0;
}