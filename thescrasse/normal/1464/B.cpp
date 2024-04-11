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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x, y, ps[maxn][2], ss[maxn][2], st;
string s;

void solve() {
    for (i = 0; i <= n + 1; i++) {
        for (j = 0; j < 2; j++) {
            ps[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        ps[i][0] = ps[i - 1][0]; ps[i][1] = ps[i - 1][1];
        if (s[i] == '0' || s[i] == '?') ps[i][0]++;
        else if (s[i] == '1') ps[i][1]++;
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j < 2; j++) {
            ss[i][j] = ps[n][j] - ps[i - 1][j];
        }
    }

    /* for (i = 1; i <= n; i++) {
        cout << ps[i][0] _ ps[i][1] << nl;
    } */

    res = 0;
    for (i = 1; i <= n; i++) {
        if (s[i] == '0' || s[i] == '?') {
            res += y * ps[i - 1][1] + x * ss[i + 1][1];
        } else if (s[i] == '1') {
            res += x * ps[i - 1][0] + y * ss[i + 1][0];
        }
    }
    res /= 2;
    m = min(m, res);

    k = 0;
    for (i = 1; i <= n; i++) {
        if (s[i] != '?') continue;
        res -= y * (ps[i - 1][1] + k) + x * ss[i + 1][1];
        res += x * (ps[i - 1][0] - k) + y * ss[i + 1][0];
        k++; m = min(m, res);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> s >> x >> y; n = s.size(); s = '#' + s + '#'; m = INF;
    // x -> 01, y -> 10

    solve();
    reverse(s.begin(), s.end()); swap(x, y);
    solve();

    cout << m << nl;

    return 0;
}