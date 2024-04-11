#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
const int oo = (int)1e9 + 7;

int n, m, nxt_state[MAXN][2], dp[2][MAXN][MAXN];
string a, b;

void minimize(int &a, int b) {a = min(a, b);}

int main() {
//    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    cin >> a;
    cin >> b;

    for(int i = 0; i < m; ++i) {
        for(int c = 0; c < 2; ++c) {
            string s = b.substr(0, i); s += (c + '0');
            nxt_state[i][c] = 0;
            for(int len = min(m-1, i+1); len > 0; --len) {
                if (b.substr(0, len) == s.substr(i-len+1, len)) {
                    nxt_state[i][c] = len;
                    break;
                }
            }
        }
    }

    int cur = 0;
    for(int k = 0; k <= n-m+1; ++k)
        for(int state = 0; state < m; ++state)
            dp[cur][k][state] = oo;
    dp[cur][0][0] = 0;

    for(int i = 0; i < n; ++i) {
        int nxt = 1 - cur;
        for(int k = 0; k <= n-m+1; ++k)
            for(int state = 0; state < m; ++state)
                dp[nxt][k][state] = oo;

//        printf("i: %d\n", i);

        for(int k = 0; k <= n-m+1; ++k) {
            for(int state = 0; state < m; ++state) {
                if (dp[cur][k][state] == oo) continue;
//                printf("k, state, dp: %d %d %d\n", k, state, dp[cur][k][state]);
                for(int c = 0; c < 2; ++c) {
                    int new_k = k;
                    if (state == m-1 && b[m-1]-'0' == c)
                        ++new_k;
                    int new_state = nxt_state[state][c];
//                    printf("c, new_k, new_state: %d %d %d\n", c, new_k, new_state);
                    minimize(dp[nxt][new_k][new_state], dp[cur][k][state] + (c != a[i]-'0'));
                }
            }
        }

        cur = nxt;
    }

    for(int k = 0; k <= n-m+1; ++k) {
        int ans = oo;
        for(int state = 0; state < m; ++state)
            ans = min(ans, dp[cur][k][state]);
        if (ans == oo)
            ans = -1;
        printf("%d ", ans);
    }

    return 0;
}