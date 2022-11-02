#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

pair<pair<int, int>, int> e[5111];
int n, x, y, dp[5111], p[5111];
void print(int x)
{
    if(dp[x]>1) print(p[x]);
    printf("%d ", e[x].second+1);
}
int main()
{
    scanf("%d%d%d", &n, &x, &y);
    for(int i=0; i<n; e[i].second=i++)
        scanf("%d%d", &e[i].first.first, &e[i].first.second);
    sort(e, e+n);
    int i=0;
    for(; i<n; ++i) {
        if(x>=e[i].first.first||y>=e[i].first.second) continue;
        dp[i] = 1;
        for(int j=0; j<i; ++j)
            if(e[i].first.first>e[j].first.first&&
               e[i].first.second>e[j].first.second)
                if(dp[i]<dp[j]+1) p[i]=j, dp[i]=dp[j]+1;
    }
    int m = max_element(dp, dp+n) - dp;
    printf("%d", dp[m]); puts("");
    if(dp[m]>0)print(m), puts("");
    return 0;
}