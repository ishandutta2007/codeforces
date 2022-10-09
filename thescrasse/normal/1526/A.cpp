#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

        while (true) {
            flag[0] = 1;
            for (i = 0; i < 2 * n; i++) {
                if (2 * a[i] == a[(i + 2 * n - 1) % (2 * n)] + a[(i + 1) % (2 * n)]) flag[0] = 0;
            }
            if (flag[0] == 1) break;
            shuffle(a, a + 2 * n, rng);
        }

        for (i = 0; i < 2 * n; i++) cout << a[i] << ' ';
        cout << nl;
    }

    return 0;
}