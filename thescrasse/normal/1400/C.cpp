#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x, r[maxn];
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
        cin >> s >> x; n = s.size();
        for (i = 0; i < n; i++) r[i] = 1;
        for (i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i - x >= 0) r[i - x] = 0;
                if (i + x < n) r[i + x] = 0;
            }
        }

        flag[1] = 1;
        for (i = 0; i < n; i++) {
            if (s[i] == '1') {
                flag[0] = 0;
                if (i - x >= 0 && r[i - x] == 1) flag[0] = 1;
                if (i + x < n && r[i + x] == 1) flag[0] = 1;
                if (flag[0] == 0) flag[1] = 0;
            }
        }

        if (flag[1] == 0) {
            cout << -1 << nl;
        } else {
            for (i = 0; i < n; i++) cout << r[i];
            cout << nl;
        }
    }

    return 0;
}