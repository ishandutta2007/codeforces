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
        cin >> n >> k;
        if (k == n - 1) {
            if (n == 4) {
                cout << -1 << nl; continue;
            }
            cout << 0 _ 2 << nl;
            cout << 1 _ n - 3 << nl;
            cout << n - 2 _ n - 1 << nl;
            for (i = 3; i < n / 2; i++) {
                a = i; b = (n - 1) - a;
                cout << a _ b << nl;
            }
            continue;
        }

        for (i = 0; i < n / 2; i++) {
            a = i; b = (n - 1) - a;
            if (a == 0) a = k;
            else if (a == k) a = 0;
            if (b == 0) b = k;
            else if (b == k) b = 0;
            cout << a _ b << nl;
        }
    }

    return 0;
}