#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, er[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i < maxn; i++) er[i] = i;
    for (i = 2; i < maxn; i++) {
        if (er[i] != i) continue;
        for (j = 2 * i; j < maxn; j += i) {
            if (er[j] == j) er[j] = i;
        }
    }

    cin >> t;
    while (t--) {
        cin >> n; res = 1; k = n + 1; flag[0] = 0;
        while (true) {
            if (er[k] >= n + 1) {
                res *= k; k += n - 1; flag[0]++;
            }
            if (flag[0] == 2) break;
            k++;
        }

        cout << res << nl;
    }

    return 0;
}