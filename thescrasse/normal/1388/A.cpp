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

    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 36) {
            cout << "YES" << nl;
            cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << 5 << nl;
            continue;
        }
        if (n == 40) {
            cout << "YES" << nl;
            cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << 9 << nl;
            continue;
        }
        if (n == 44) {
            cout << "YES" << nl;
            cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << 13 << nl;
            continue;
        }

        if (n >= 31) {
            cout << "YES" << nl;
            cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}