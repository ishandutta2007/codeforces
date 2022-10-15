#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
int prime[66], cntPrime, n, a[111], dp[111][133333], prev[111][133333], ans[111], num[111][133333], mul[133333], msk[66];
bool f[66];
vector<int> vec, trans[133333];
int main()
{
    prime[0] = 0x7fffffff;
    memset(f, true, sizeof(f));
    cntPrime = 0;
    for(int i = 2; i <= 60; i++) {
        if(f[i]) prime[++cntPrime] = i;
        for(int j = 1; j <= cntPrime and prime[j] * i <= 60 and i % prime[j - 1]; j++)
            f[prime[j] * i] = false;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0][(1 << cntPrime) - 1] = 0;
    prev[0][(1 << cntPrime) - 1] = 0;
    for(int i = 1; i < 60; i++) {
        msk[i] = 0;
        for(int j = 1; j <= cntPrime; j++)
            if(i % prime[j] == 0)
                msk[i] |= (1 << j - 1);
    }
    for(int i = 0; i < (1 << 17); i++) {
        for(int j = 1; j < 60; j++)
            if(msk[j] == (i & msk[j])) {
                trans[i].push_back(j);
            }
    }
    //printf("%d\n", vec.size());
//  printf("%d %d\n", mul[3], mul[7]);
    for(int i = 0; i < n; i++) { for(int j = 0; j < (1 << 17); j++) if(dp[i][j] != 0x7f7f7f7f){
        for(int k = 0; k < (int)trans[j].size(); k++) {
            int x(trans[j][k]);
            if(dp[i + 1][j - msk[x]] > dp[i][j] + abs(a[i + 1] - x)) {
                prev[i + 1][j - msk[x]] = j;
                num[i + 1][j - msk[x]] = x;
                dp[i + 1][j - msk[x]] = dp[i][j] + abs(a[i + 1] - x);
            }
        }
    }}
    //printf("%d %d\n", mul[1], dp[2][(1 << cntPrime) - 5]);
    int p = 0;
    for(int i = 1; i < (1 << 17); i++)
        if(dp[n][i] < dp[n][p])
            p = i;
    for(int i = n; i >= 1; i--) {
        ans[i] = num[i][p];
        p = prev[i][p];
    }
    //printf("%d\n", clock());
    for(int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n?'\n':' ');
    fclose(stdin);
    return 0;
}