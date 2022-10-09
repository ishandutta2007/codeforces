#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x;
string s, o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k >> s; o = s; flag[0] = 1;
        for (i = 0; i < n; i++) {
            x = i % k;
            if (s[i] == '?') continue;
            if (o[x] == '?') {
                o[x] = s[i]; continue;
            }
            if (s[i] != o[x]) flag[0] = 0;
        }

        if (flag[0] == 0) {
            cout << "NO" << nl; continue;
        }

        // cout << o << nl;

        flag[0] = 0; flag[1] = 0;
        for (i = 0; i < k; i++) {
            if (o[i] == '0') flag[0]++;
            if (o[i] == '1') flag[1]++;
        }

        if (flag[0] > k / 2 || flag[1] > k / 2) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }
    }

    return 0;
}