#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < n; i++) cin >> a[i];

    if (n > m) {
        cout << 0; return 0;
    }

    res = 1;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            k = abs(a[i] - a[j]);
            res *= k; res %= m;
        }
    }

    cout << res;

    return 0;
}