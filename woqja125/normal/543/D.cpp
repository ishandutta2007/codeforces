#include<stdio.h>
#include<vector>
const int MOD = 1000000007;
std::vector<int> map[200001];
int dp1[200001], dp2[200001], par[200001];
void dfs1(int x, int p)
{
    dp1[x] = 1;
    par[x] = p;
    for(auto xx: map[x])
    {
        if(xx==p) continue;
        dfs1(xx, x);
        dp1[x] = 1ll*dp1[x]*dp1[xx]%MOD;
    }
    dp1[x] = (dp1[x] + 1)%MOD;
}
void dfs2(int x, int p)
{
    int i;
    std::vector<int> g1(map[x].size()+5, 0), g2(map[x].size()+5, 0);
    g1[0] = g2[map[x].size()+1] = 1;
    for(i=1; i<=map[x].size(); i++)
    {
        int xx = map[x][i-1];
        if(xx == p) g1[i] = g1[i-1];
        else g1[i] = 1ll*g1[i-1]*dp1[xx]%MOD;
    }
    for(i=map[x].size(); i>=1; i--)
    {
        int xx = map[x][i-1];
        if(xx == p) g2[i] = g2[i+1];
        else g2[i] = 1ll*g2[i+1]*dp1[xx]%MOD;
    }
    for(i=0; i<map[x].size(); i++)
    {
        int xx = map[x][i];
        if(xx == p) continue;
        dp2[xx] = (1ll*g1[i]*g2[i+2])%MOD;
        dp2[xx] = 1ll*dp2[xx]*dp2[x]%MOD;
        dp2[xx]+=1;
        dp2[xx]%=MOD;
        dfs2(xx, x);
    }
}
int main()
{
    int n, t;
    int i;
    scanf("%d", &n);
    for(i=2; i<=n; i++)
    {
        scanf("%d", &t);
        map[t].push_back(i);
        map[i].push_back(t);
    }
    dfs1(1, -1);
    dp2[1] = 1;
    dfs2(1, -1);
    for(i=1; i<=n; i++)
    {
        int ans = 1;
        for(auto xx: map[i])
        {
            if(xx == par[i]) ans = 1ll*ans*dp2[i]%MOD;
            else ans = 1ll*ans*dp1[xx]%MOD;
        }
        ans = (ans)%MOD;
        printf("%d ", ans);
    }
    return 0;
}