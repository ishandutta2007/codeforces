//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2005;
vector<int>G[2][maxn];
int dp[maxn],val[2][maxn][maxn],l[2][maxn],r[2][maxn],sz[2][maxn],n,a;

void dfs(int k,int x)
{
    if(x!=1)
        sz[k][x]=1;
    for(int i=0;i<G[k][x].size();i++)
    {
        int v=G[k][x][i];
        dfs(k,v);
        l[k][x]=min(l[k][x],l[k][v]);
        r[k][x]=max(r[k][x],r[k][v]);
        sz[k][x]+=sz[k][v];
    }
    val[k][l[k][x]][r[k][x]]=max(val[k][l[k][x]][r[k][x]],sz[k][x]);
}

int main()
{
    sync;
    cin>>n;
    for(int k=0;k<2;k++)
    {
        cin>>a;
        for(int i=1;i<=a;i++)
        {
            l[k][i]=a+1;
            r[k][i]=0;
        }
        for(int i=2;i<=a;i++)
        {
            int x;
            cin>>x;
            G[k][x].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            l[k][x]=r[k][x]=i;
        }
        dfs(k,1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            dp[j]=max(dp[j],dp[i-1]+max(val[0][i][j],val[1][i][j]));
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}