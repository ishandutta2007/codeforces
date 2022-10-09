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
        cin >> n >> s; s = '#' + s;

        while (true) {
            flag[0] = 0;
            for (i = 1; i <= n; i++) {
                if (s[i] == '?') continue;
                for (j = i - 1; j <= i + 1; j += 2) {
                    if (j <= 0 || j >= n + 1) continue;
                    if (s[j] == '?') {
                        flag[0] = 1;
                        if (s[i] == 'B') s[j] = 'R';
                        else s[j] = 'B';
                    }
                }
            }
            // cout << s << nf;
            if (flag[0] == 0) {
                if (s[1] == '?') s[1] = 'B';
                else break;
            }
        }

        for (i = 1; i <= n; i++) cout << s[i];
        cout << nl;
    }

    return 0;
}