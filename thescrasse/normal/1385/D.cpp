#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 600010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, sg[maxn], cr, p2;
string s;
char x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> s; p2 = n / 2; x = 'a'; cr = 2;
        for (i = 0; i <= 4 * n; i++) sg[i] = 0;
        while (p2 >= 1) {
            for (i = 0; i < n; i += p2) {
                // cout << "i, cr = " << i << ' ' << cr << nl;
                if (p2 != n / 2) {
                    k = cr / 2;
                    if (k % 2 == 0) k++;
                    else k--;
                    sg[cr] += sg[k];
                    // cout << "k = " << k << nl;
                }
                for (j = i; j < i + p2; j++) {
                    if (s[j] != x) {
                        // cout << "s" << j << " != " << x << nl;
                        sg[cr]++;
                    }
                }
                cr++;
            }
            p2 /= 2; x++;
        }

        for (i = 2 * n; i < 3 * n; i++) {
            k = i - n;
            if (k % 2 == 0) k++;
            else k--;
            sg[i] += sg[k];
            sg[i] += (s[i - 2 * n] != x);
        }

        res = INF;
        for (i = 2 * n; i < 3 * n; i++) {
            res = min(res, sg[i]);
        }

        /* for (i = 1; i < 3 * n; i++) cout << i << ' ' << sg[i] << ' ';
        cout << nl; */

        cout << res << nl;
    }

    return 0;
}