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
        if (n == 1) {
            flag[0] = 0;
        } else if (n % 2 == 1) {
            flag[0] = 1;
        } else if (n == 2) {
            flag[0] = 1;
        } else if (n % 4 == 0) {
            while (n % 2 == 0) n /= 2;
            if (n == 1) flag[0] = 0;
            else flag[0] = 1;
        } else {
            n /= 2; flag[0] = 0;
            for (i = 2; i * i <= n; i++) {
                if (n % i == 0) flag[0] = 1;
            }
        }

        if (flag[0] == 0) cout << "FastestFinger" << nl;
        else cout << "Ashishgup" << nl;
    }

    return 0;
}