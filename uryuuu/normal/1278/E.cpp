#include<iostream>
#include<stdio.h>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=500005;
const ll Mod=1e9+7;

vector<int>g[maxn];
int n,l[maxn],r[maxn],cnt;

void dfs(int x,int fa)
{
    for(int i=g[x].size()-1;i>=0;i--)
    {
        int v=g[x][i];
        if(v==fa)
            continue;
        l[v]=cnt++;
    }
    r[x]=cnt++;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==fa)
            continue;
        dfs(v,x);
    }
}

int main()
{
    sync;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt=1;
    l[1]=cnt++;
    dfs(1,-1);
    for(int i=1;i<=n;i++)
    {
        cout<<l[i]<<' '<<r[i]<<endl;
    }
    return 0;
}