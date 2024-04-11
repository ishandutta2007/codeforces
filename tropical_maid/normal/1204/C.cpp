#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/20, 23:44:32
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int inf = 1e8;
int n, m;
int E[101][101];
int D[101][101];
int P[1000001];
int sum[1000001];
int dp[1000001];
int pr[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char go[102];
        cin >> go + 1;
        for (int j = 1; j <= n; ++j) {
            E[i][j] = D[i][j] = (go[j] == '0' ? inf : 1);
        }
        E[i][i] = D[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    cin >> m >> P[1];
    for (int i = 2; i <= m; ++i) {
        cin >> P[i];
        sum[i] = sum[i - 1] + D[P[i - 1]][P[i]];
    }
    dp[1] = 1;
    pr[1] = 0;
    for (int i = 2, j = 1; i <= m; ++i) {
        while (D[P[j]][P[i]] != sum[i] - sum[j]) ++j;
        dp[i] = dp[j] + 1;
        pr[i] = j;
    }
    printf("%d\n", dp[m]);
    vector<int> ans;
    for (int i = m; i > 0; i = pr[i]) ans.push_back(P[i]);
    for (int i = ans.size(); i--; ) printf("%d ", ans[i]);
    return 0;
}