#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, v[70];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i <= 60; i++) {
        for (j = 0; j <= 15; j++) {
            if ((j * (j + 1)) / 2 > i) {
                v[i] = j - 1; break;
            }
        }
    }

    res = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a; res ^= v[a];
    }

    if (res == 0) cout << "YES";
    else cout << "NO";

    return 0;
}