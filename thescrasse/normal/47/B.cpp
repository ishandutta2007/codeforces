#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[3], b, x, y;
string s[3];
char o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> s[0] >> s[1] >> s[2];
    a[0] = 0; a[1] = 1; a[2] = 2;
    do {
        flag[0] = 1;
        // cout << a[0] << ' ' << a[1] << ' ' << a[2] << nl;
        for (i = 0; i < 3; i++) {
            if (s[i][1] == '>') swap(s[i][0], s[i][2]);
            x = (ll)s[i][0] - 65; y = (ll)s[i][2] - 65;
            if (s[i][1] == '>') swap(s[i][0], s[i][2]);
            if (a[x] > a[y]) {
                // cout << x << ' ' << y << nl;
                flag[0] = 0; break;
            }
        }

        if (flag[0] == 1) {
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (a[j] == i) {
                        o = (char)j + 65; cout << o;
                    }
                }
            }
            cout << nl; break;
        }
    } while (next_permutation(a, a + 3));

    if (flag[0] == 0) cout << "Impossible";

    return 0;
}