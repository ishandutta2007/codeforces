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
#include<unordered_map>
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

vector<int>g[maxn];
int dep[maxn];
int f=0;

int s;

void dfs(int u,int fa)
{
    int v;
    int sum=0;
    dep[u]=dep[fa]+1;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(v==fa)
            continue;
        dfs(v,u);
        if(g[v].size()==1)
        sum++;
    }
    if(sum>0)
    {
        s-=(sum-1);
    }
}






int main()
{
    sync;
    
    int n,t;
    cin>>n;
    int u,v;
    int rt;
    dep[0]=0;
    s=n-1;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()>1)
        {
            rt=i;
            break;
        }
    }
    dfs(rt,0);
    int a=0,b=0;
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==1)
        {
            if(dep[i]%2)
                a++;
            else
                b++;
        }
    }
    if(a&&b)
        cout<<3<<' '<<s<<endl;
    else
        cout<<1<<' '<<s<<endl;
    
    return 0;
}