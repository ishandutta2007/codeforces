#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 7, K = 1e3 + 7;
int dp[N][K];
int d[N];

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> d[i];
    }
    int g, r;
    cin >> g >> r;
    sort(d + 1, d + m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= g; j++) {
            dp[i][j] = -1; 
        }
    }
    vector <vector <int>> cur(g + 1);
    dp[1][0] = 0;
    long long res = -1;
    cur[0].push_back(1);
    int curt = 0;
    while (!cur[0].empty()) {
        for (int i = 0; i < g; i++) {
            for (int elem : cur[i]) {
                //cout << curt << ' ' << i << ' ' << elem << endl;
                if (elem != 1) {
                    int val = d[elem] - d[elem - 1];
                    if (i + val <= g && dp[elem - 1][i + val] == -1) {
                        dp[elem - 1][i + val] = curt;
                        cur[i + val].push_back(elem - 1);
                    }
                }
                if (elem != m) {
                    int val = d[elem + 1] - d[elem];
                    if (i + val <= g && dp[elem + 1][i + val] == -1) {
                        dp[elem + 1][i + val] = curt;
                        cur[i + val].push_back(elem + 1);
                    }
                }
            }
            cur[i].clear();
        }
        //cout << 53 << endl;
        for (int elem : cur[g]) {
            if (elem != 1) {
                //cout << "! " << elem << endl;
                cur[0].push_back(elem);
                dp[elem][0] = curt + 1;
            }
        }
        cur[g].clear();
        curt++;
    }
    for (int i = 0; i <= g; i++) {
        if (dp[m][i] != -1) {
            if (res == -1) res = dp[m][i] * (r + g) + i; 
            res = min(res, dp[m][i] * (r + g) + i);
        }
    }
    cout << res << endl;
}