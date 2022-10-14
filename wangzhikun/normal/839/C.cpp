#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define N 100000+10
vector<int>G[N];
int p[N],n;
double ans=0;
void read_tree()
{
    int u, v;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
void dfs(int u, int fa ,int len,double psblt)
{
    int d = G[u].size();
    double e = G[u].size();
    if(u == 1)e+=1;
    if(d == 1&&u!=1){
        ans+=len*psblt;
    }
    for (int i = 0; i < d; i++)
    {
        int v = G[u][i];
        if (v != fa)
        dfs(v, p[v] = u,len+1,psblt/(e-1));
    }
}
int main()
{
    read_tree();
    int root = 1;
    p[root] = -1;
    dfs(root, -1,0,1);
    printf("%.15lf",ans);
    return 0;
}