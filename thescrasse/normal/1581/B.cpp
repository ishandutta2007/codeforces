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
        cin >> n >> m >> k; k -= 2;
        if (m < n - 1 || m > (n * (n - 1)) / 2) {
            cout << "NO" << nl; continue;
        }

        if (m != (n * (n - 1)) / 2) k--;
        if (n == 1) k++;
        if (k >= 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}