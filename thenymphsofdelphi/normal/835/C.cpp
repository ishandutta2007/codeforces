#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int dp[12][N][N], cnt[12][N][N];
int n, q, c;

void init(){
    for (int p = 0; p <= c; p++){
        for (int x = 1; x <= N; x++){
            for (int y = 1; y <= N; y++){
                dp[p][x][y] = dp[p][x-1][y] + dp[p][x][y-1] - dp[p][x-1][y-1] + cnt[p][x][y];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++){
        int x, y, s;
        cin >> x >> y >> s;
        cnt[s][x][y]++;
    }
    init();
    for (int i = 0; i < q; i++){
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int p = 0; p <= c; p++){
            int temp = (p + t) % (c + 1);
            temp *= dp[p][x2][y2] - dp[p][x1-1][y2] - dp[p][x2][y1-1] + dp[p][x1-1][y1-1];
            ans += temp;
        }
        cout << ans << endl;
    }
}