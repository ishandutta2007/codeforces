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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

int n,a[maxn],dp[maxn];
vi g[maxn];
int vis[maxn];
queue<int>q;

void bfs()
{
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
//            cout<<u<<' '<<v<<endl;
            if(vis[v])
                continue;
            if((a[u]-a[v])%2==0)
            {
                dp[v]=dp[u]+1;
                q.push(v);
                vis[v]=1;
            }
        }
    }
    return;
}

int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(dp,inf,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(i-a[i]>=1)
        {
            if((a[i-a[i]]-a[i])%2)
                dp[i]=1;
            g[i-a[i]].push_back(i);
        }
        if(i+a[i]<=n)
        {
            if((a[i+a[i]]-a[i])%2)
                dp[i]=1;
            g[i+a[i]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==1)
        {
            q.push(i);
            vis[i]=1;
        }
    }
    bfs();
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==inf)
            cout<<-1<<' ';
        else
            cout<<dp[i]<<' ';
    }
    cout<<endl;
    return 0;
}