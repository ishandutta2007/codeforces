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
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int p[maxn];
ll s[maxn];
vector<int>g[maxn];
int f;
ll sum;

void dfs(int u,int fa)
{
    int v;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        dfs(v,u);
    }
    if(s[u]==-1)
    {
        if(g[u].size()==0)
        {
            s[u]=s[fa];
        }
        else
        {
            s[u]=s[g[u][0]];
            for(int i=1;i<g[u].size();i++)
            {
                v=g[u][i];
                s[u]=min(s[u],s[v]);
            }
        }
    }
    return;
}

void dfs2(int u,int fa)
{
    if(s[u]<s[fa])
    {
        f=1;
        return;
    }
    sum+=1ll*(s[u]-s[fa]);
    int v;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        dfs2(v,u);
    }
}

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        g[p[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    f=0;
    sum=0;
    s[0]=0;
    dfs(1,0);
    dfs2(1,0);
    if(f)
        cout<<-1<<endl;
    else
        cout<<sum<<endl;
    return 0;
}