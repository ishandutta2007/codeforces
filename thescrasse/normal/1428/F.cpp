// 1428F
// Fruit Sequences

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, p[maxn], l;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s; s = '#' + s; p[0] = n; l = 1;
    for (i = 1; i <= n + 1; i++) {
        if (i <= n && s[i] == '1') {
            k++; continue;
        }

        res += m;
        for (j = 1; j <= k; j++) {
            m += l - 1 - p[j]; res += m;
        }

        for (j = 1; j <= k; j++) {
            p[j] = l + k - j;
        }

        res += (k * (k + 1) * (k + 2)) / 6;
        m += (k * (k + 1)) / 2;
        l = i + 1; k = 0;

        /* cout << "i = " << i << nl;
        for (j = 0; j <= n; j++) cout << p[j] << ' ';
        cout << nl;
        cout << m << ' ' << res << nl; */
    }

    cout << res;

    return 0;
}