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
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> s;
        flag[0] = 0; flag[1] = 0; flag[2] = 0; flag[3] = 0;
        for (i = 0; i < n; i++) {
            k = (i + 1) % 2; m = (ll)s[i] % 2;
            flag[2 * k + m] = 1;
        }

        if (n % 2 == 0) {
            if (flag[0] == 1) cout << "2" << nl;
            else cout << "1" << nl;
        } else {
            if (flag[3] == 0) cout << "2" << nl;
            else cout << "1" << nl;
        }
    }

    return 0;
}