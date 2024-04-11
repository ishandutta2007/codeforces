#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endld
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[3], b[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[1] != a[2]) {
            cout << "NO" << nl; continue;
        }
        cout << "YES" << nl;
        cout << a[2] << ' ' << a[0] << ' ' << 1 << nl;
    }

    return 0;
}