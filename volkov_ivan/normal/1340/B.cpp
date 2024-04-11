#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2007;
bool dp[N][N];
string cur[N];
int dst[N][10];
vector <string> dig = {
"1110111",
"0010010",
"1011101",
"1011011",
"0111010",
"1101011",
"1101111",
"1010010",
"1111111",
"1111011"
};

int diff(string cur, string need) {
    int res = 0;
    for (int i = 0; i < (int) cur.size(); i++) {
        if (cur[i] == '0' && need[i] == '1') res++;
        if (cur[i] == '1' && need[i] == '0') return -1;
    }
    return res;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> cur[i];
    reverse(cur + 1, cur + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dst[i][j] = diff(cur[i], dig[j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int lst = 0; lst <= 9; lst++) {
                int c = dst[i][lst];
                if (c != -1 && c <= j && dp[i - 1][j - c]) {
                    dp[i][j] = 1;
                    break;
                }
            }
        }
    }
    if (!dp[n][k]) {
        cout << -1 << endl;
        return 0;
    }
    string ans = "";
    int rest = k;
    for (int i = n; i >= 1; i--) {
        for (int lst = 9; lst >= 0; lst--) {
            int c = dst[i][lst];
            if (c != -1 && c <= rest && dp[i - 1][rest - c]) {
                ans += '0' + lst;
                rest -= c;
                break;
            }
        }
    }
    cout << ans << endl;
}