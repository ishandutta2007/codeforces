#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int dp[maxn][maxn];
pair<int, int> fr[maxn][maxn];

int main() {
    string a, b; cin >> a >> b;
    int n = (int)a.size(), m = (int)b.size();
    a = ',' + a; b = ',' + b;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = maxn + maxn;
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i && j && a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
                fr[i][j] = make_pair(i - 1, j - 1);
            }
            if (i && dp[i - 1][j] + 1 < dp[i][j]) {
                // delete
                dp[i][j] = dp[i - 1][j] + 1;
                fr[i][j] = make_pair(i - 1, j);
            } 
            if (j && dp[i][j - 1] + 1 < dp[i][j]) {
                // insert
                dp[i][j] = dp[i][j - 1] + 1;
                fr[i][j] = make_pair(i, j - 1);
            }
            if (i && j && dp[i - 1][j - 1] + 1 < dp[i][j]) {
                // replace
                dp[i][j] = dp[i - 1][j - 1] + 1;
                fr[i][j] = make_pair(i - 1, j - 1);
            }
        }
    }
    cout << dp[n][m] << endl;
    int i = n, j = m;
    stack<tuple<string, int, char>> stk;
    while (i > 0 || j > 0) {
        int toi = fr[i][j].first, toj = fr[i][j].second;
        if (a[i] == b[j] && toi == i - 1 && toj == j - 1) {
            i = toi; j = toj;
            continue;
        }
        if (toi == i - 1 && toj == j - 1) stk.emplace("REPLACE", i, b[j]);
        if (toi == i - 1 && toj == j) stk.emplace("DELETE", i, 'a');
        if (toi == i && toj == j - 1) stk.emplace("INSERT", i + 1, b[j]);
        i = toi; j = toj;
    } 
    int now = 0;
    while (stk.size()) {
        string op; int pos; char c; tie(op, pos, c) = stk.top(); stk.pop();
        pos += now;
        cout << op << ' ' << pos;
        if (op == "INSERT") ++now;
        else if (op == "DELETE") --now;
        if (op != "DELETE") cout << " " << c;
        cout << endl;
    }
    return 0;
}