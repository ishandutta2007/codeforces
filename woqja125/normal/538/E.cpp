#include<stdio.h>
#include<vector>
#include<string.h>
std::vector<int> map[200001];
int dp[200001];
int leaf = 0;
int get1();
int get2();
int main()
{
    int n, a, b, i;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    //
    printf("%d ", leaf-get1()+1);
    //
    printf("%d ", get2());
    return 0;
}

void dfs1(int x, int p, int t)
{
    int i, c=0;
    for(i=0; i<map[x].size(); i++)
    {
        if(map[x][i] == p) continue;
        c++;
        dfs1(map[x][i], x, 1-t);
    }
    if(c == 0)
    {
        leaf++;
        dp[x] = 1;
        return;
    }
    if(t == 0)
    {
        int min = 1000000;
        for(i=0; i<map[x].size(); i++)
        {
            if(map[x][i] == p) continue;
            if(dp[map[x][i]] < min) min = dp[map[x][i]];
        }
        dp[x] = min;
    }
    if(t == 1)
    {
        dp[x] = 0;
        for(i=0; i<map[x].size(); i++)
        {
            if(map[x][i] == p) continue;
            dp[x] += dp[map[x][i]];
        }
    }
}

int get1()
{
    memset(dp, -1, sizeof(dp));
    dfs1(1, -1, 0);
    return dp[1];
}

void dfs2(int x, int p, int t)
{
    int i, c=0;
    for(i=0; i<map[x].size(); i++)
    {
        if(map[x][i] == p) continue;
        c++;
        dfs2(map[x][i], x, 1-t);
    }
    if(c == 0)
    {
        dp[x] = 1;
        return;
    }
    if(t == 1)
    {
        int min = 1000000;
        for(i=0; i<map[x].size(); i++)
        {
            if(map[x][i] == p) continue;
            if(dp[map[x][i]] < min) min = dp[map[x][i]];
        }
        dp[x] = min;
    }
    if(t == 0)
    {
        dp[x] = 0;
        for(i=0; i<map[x].size(); i++)
        {
            if(map[x][i] == p) continue;
            dp[x] += dp[map[x][i]];
        }
    }
}

int get2()
{
    memset(dp, -1, sizeof(dp));
    dfs2(1, -1, 0);
    return dp[1];
}