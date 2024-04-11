#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(10);

    int n;
    vector<int> k(4);
    rep(i, 1, 4) cin >> k[i];
    n = k[1] + k[2] + k[3];
    vector<int> b(n + 2), t(n + 2, 1e9);
    rep(i, 1, 4) {
        rep(j, 0, k[i]) {
            int c;
            cin >> c;
            b[c] = i;
        }
    }
    vector<vector<int>> s(4, vector<int>(n + 2));
    rep(i, 1, n + 1) {
        s[b[i]][i]++;
        if (b[i] == 2)
            s[0][i]++;
        s[1][i + 1] = s[1][i];
        s[3][i + 1] = s[3][i];
        s[0][i + 1] = s[0][i];
    }
    for (int i = n; i > 0; i--) {
        s[2][i - 1] += s[2][i];
    }
    rep(i, 1, n + 2) t[i] = s[2][i] + s[3][i - 1];
    /*
    rep(j, 0, n + 2) {
        cout << b[j] << ((j != n + 1) ? ' ' : '\n');
    }
    rep(j, 0, n + 2) {
        cout << t[j] << ((j != n + 1) ? ' ' : '\n');
    }
    */
    int ans = k[2] + k[3];
    for (int i = n + 1; i > 0; i--)
        t[i - 1] = min(t[i - 1], t[i]);
    /*
rep(j, 0, n + 2) {
    cout << t[j] << ((j != n + 1) ? ' ' : '\n');
}
*/
    rep(s2, 1, n + 1) {
        int sum1 = s[1][n + 1] - 2 * s[1][s2 - 1] + s2 - 1;
        ans = min(ans, sum1 + t[s2] - s[3][s2 - 1]);
    }
    cout << ans << endl;
}