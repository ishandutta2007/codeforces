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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

struct node
{
    int siz,dep;
}a[maxn];
vector<int>g[maxn];

void dfs(int u,int fa)
{
    int v;
    a[u].dep=a[fa].dep+1;
    a[u].siz=1;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(v==fa)
            continue;
        dfs(v,u);
        a[u].siz+=a[v].siz;
    }
    return;
}

bool cmp(node a,node b)
{
    return a.dep-a.siz+1>b.dep-b.siz+1;
}

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    a[0].dep=-1;
    a[0].siz=0;
    dfs(1,0);
    sort(a+1,a+n+1,cmp);
    ll sum=0;
    for(int i=1;i<=k;i++)
    {
        sum+=1ll*(a[i].dep-a[i].siz+1);
    }
    cout<<sum<<endl;
    
    return 0;
}