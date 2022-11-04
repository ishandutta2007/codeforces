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
#define lb(x) (x&(-x));
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;

struct node
{
    int to,nxt,w;
}e[maxn<<1];
ll head[maxn],tot,sum[maxn],cnt[maxn],zx[maxn],b[maxn];

void add(int u,int v,int w)
{
    e[tot].to=v;
    e[tot].nxt=head[u];
    e[tot].w=w;
    head[u]=tot++;
}

int n,k;

bool cmp(int a,int b)
{
    return a>b;
}

void dfs(int u,int fa)
{
    int ct=0;
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        dfs(v,u);
    }
    
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        sum[u]+=sum[v];
        if(cnt[v]==k)
        {
            if(e[i].w-zx[v]>0)
            {
                b[ct++]=e[i].w-zx[v];
            }
        }
        else
        {
            b[ct++]=e[i].w;
        }
    }
    sort(b,b+ct,cmp);
    for(int i=0;i<min(k,ct);i++)
    {
        sum[u]+=b[i];
        cnt[u]++;
        zx[u]=b[i];
    }
    return;
}


int main()
{
    sync;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            head[i]=-1;
            sum[i]=0;
            cnt[i]=0;
            zx[i]=0;
        }
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        int u,v,w;
        tot=0;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }
        dfs(1,0);
        cout<<sum[1]<<endl;
    }
    
    return 0;
}