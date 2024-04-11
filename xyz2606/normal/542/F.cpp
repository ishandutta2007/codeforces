#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(1111);
vector<int> vec[N];
int dp[N][N];
int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for(int i(1); i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        vec[x].push_back(y);
    }
    for(int i(1); i <= t; i++) {
        sort(vec[i].begin(), vec[i].end());
    }
    memset(dp, -1, sizeof(dp));
    dp[t][1] = 0;
    if(!vec[t].empty()) {
        dp[t][0] = vec[t].back();
    }
    for(int i(t); i > 0; i--) {
        for(int j(0); j <= n; j++) {
            if(dp[i][j] != -1) {
                int sum(0);
                for(int k(0); k <= 2 * j && k <= vec[i - 1].size(); k++) {
                    dp[i - 1][min(n, j * 2 - k)] = max(dp[i - 1][min(n, j * 2 - k)], dp[i][j] + sum);
                    if(k != vec[i - 1].size()) {
                        sum += vec[i - 1][vec[i - 1].size() - k - 1];
                    }
                }
            }
        }
    }
    int ans(0);
    for(int i(0); i <= n; i++) {
        ans = max(ans, dp[0][i]);
    }
    printf("%d\n", ans);
}