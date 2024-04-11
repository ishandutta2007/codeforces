#include <bits/stdc++.h>

const int N = 60;
const int M = 20010;

int a[N][M], pre[N][M];
int dp[N][M];
int premax[N][M], sufmax[N][M];

int getpre(int i, int l, int r){
    return pre[i][r] - pre[i][l - 1];
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i){
        for (int j = 1; j <= m; ++ j){
            scanf("%d", &a[i][j]);
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
    }
    for (int j = 1; j <= m - k + 1; ++ j){
        dp[0][j] = getpre(0, j, j + k - 1) + getpre(1, j, j + k - 1);
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j <= m - k + 1; ++ j){
            premax[i][j] = std::max(premax[i][j - 1], dp[i - 1][j]);
        }
        for (int j = m - k + 1; j >= 1; -- j){
            sufmax[i][j] = std::max(sufmax[i][j + 1], dp[i - 1][j]);
        }
        for (int j = 1; j <= m - k + 1; ++ j){
            int x = j - k;
            int value = getpre(i, j, j + k - 1);
            if (x >= 1){
                dp[i][j] = premax[i][x] + value;
            }
            x = j + k;
            if (x <= m - k + 1){
                dp[i][j] = std::max(dp[i][j], sufmax[i][x] + value);
            }
        }
        std::vector <int> vec(M);
        for (int j = 0; j < M; ++ j){
            int x = j + k - 1;
            vec[j] = dp[i - 1][j] - (x < M ? pre[i][x] : 0);
        }
        std::deque <int> queue;
        for (int j = 1; j <= m - k + 1; ++ j){
            int to_pop = j - k;
            if (!queue.empty() && queue.front() == to_pop){
                queue.pop_front();
            }
            while (!queue.empty() && vec[queue.back()] <= vec[j]){
                queue.pop_back();
            }
            queue.push_back(j);
            dp[i][j] = std::max(dp[i][j], vec[queue.front()] + pre[i][j + k - 1]);
        }
        for (int j = 1; j < M; ++ j){
            vec[j] = dp[i - 1][j] + pre[i][j - 1];
        }
        queue.clear();
        for (int j = m - k + 1; j >= 1; -- j){
            int to_pop = j + k;
            if (!queue.empty() && queue.front() == to_pop){
                queue.pop_front();
            }
            while (!queue.empty() && vec[queue.back()] <= vec[j]){
                queue.pop_back();
            }
            queue.push_back(j);
            dp[i][j] = std::max(dp[i][j], vec[queue.front()] - pre[i][j - 1]);
        }
        for (int j = 1; j <= m - k + 1; ++ j){
            dp[i][j] += getpre(i + 1, j, j + k - 1);
        }
    }
    int max = 0;
    for (int i = 1; i <= m - k + 1; ++ i){
        max = std::max(max, dp[n - 1][i]);
    }
    printf("%d\n", max);
}