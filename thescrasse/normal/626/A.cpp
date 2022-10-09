#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 210

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, pr[maxn][2];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s;
    pr[0][0] = 0; pr[0][1] = 0;
    for (i = 1; i <= n; i++) {
        if (s[i - 1] == 'U') {
            a = 1; b = 0;
        }
        if (s[i - 1] == 'R') {
            a = 0; b = 1;
        }
        if (s[i - 1] == 'D') {
            a = -1; b = 0;
        }
        if (s[i - 1] == 'L') {
            a = 0; b = -1;
        }
        pr[i][0] = pr[i - 1][0] + a;
        pr[i][1] = pr[i - 1][1] + b;
    }

    res = 0;
    for (i = 0; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (pr[i][0] == pr[j][0] && pr[i][1] == pr[j][1]) res++;
        }
    }

    cout << res;

    return 0;
}