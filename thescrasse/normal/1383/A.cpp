#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10];
string a, b, ch;
char x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ch = "abcdefghijklmnopqrst";
    cin >> t;
    while (t--) {
        cin >> n >> a >> b; flag[0] = 1;
        for (i = 0; i < n; i++) {
            if (a[i] > b[i]) flag[0] = 0;
        }
        if (flag[0] == 0) {
            cout << -1 << nl; continue;
        }

        res = 0;
        for (i = 0; i < 19; i++) {
            flag[0] = 0; x = 'z';
            for (j = 0; j < n; j++) {
                if (a[j] == ch[i] && b[j] > ch[i]) {
                    x = min(x, b[j]); flag[0] = 1;
                }
            }

            if (flag[0] == 1) {
                res++;
                for (j = 0; j < n; j++) {
                    if (a[j] == ch[i] && b[j] != a[j]) a[j] = x;
                }
            }
            // cout << a << nl;
        }

        cout << res << nl;
    }

    return 0;
}