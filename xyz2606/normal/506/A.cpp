#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
const int N(33333), infi(1e9);
int cnt[N];
vector<pair<int, int> > dp[N];
__inline void renew(int i, int j, int k) {
    if(j <= 0 or i + j > 30000) {
        return;
    }
    bool flag = false;
    for(int o(1); o <= 3; o++) {
        if((int)dp[i + j].size() - o >= 0) {
            pair<int, int> & tmp(dp[i + j][dp[i + j].size() - o]);
            if(tmp.first == j) {
                tmp.second = max(tmp.second, k + cnt[i + j]);
                flag = true;
                break;  
            }
        }
    }
    if(!flag) {
        dp[i + j].push_back(make_pair(j, k + cnt[i + j]));
    }   
}
int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for(int i(1); i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int ans(cnt[d]);
    dp[d].push_back(make_pair(d, cnt[d]));
    for(int i(d); i <= 30000; i++) {
        for(int j(0); j < (int)dp[i].size(); j++) {
            renew(i, dp[i][j].first + 1, dp[i][j].second);
            renew(i, dp[i][j].first + 0, dp[i][j].second);
            renew(i, dp[i][j].first - 1, dp[i][j].second);
            ans = max(ans, dp[i][j].second);
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    return 0;
}