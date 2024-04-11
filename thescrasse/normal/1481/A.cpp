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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x, y, u, l, d, r;
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
        cin >> x >> y >> s; n = s.size(); s = '#' + s;
        u = 0; l = 0; d = 0; r = 0;
        for (i = 1; i <= n; i++) {
            if (s[i] == 'U') u++;
            else if (s[i] == 'L') l++;
            else if (s[i] == 'D') d++;
            else if (s[i] == 'R') r++;
        }
        flag[0] = 1;
        if (x > 0 && r < x) flag[0] = 0;
        if (y > 0 && u < y) flag[0] = 0;
        if (x < 0 && l < -x) flag[0] = 0;
        if (y < 0 && d < -y) flag[0] = 0;

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}