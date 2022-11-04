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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

int a[maxn],d[maxn],cnt[maxn];
int n,m,k;

struct node
{
    int to,nxt;
}e[maxn];

int head[maxn],tot;

void add(int u,int v)
{
    e[tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

void bfs()
{
    int u=a[k];
    queue<int>q;
    d[u]=0;
    q.push(u);
    int v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            v=e[i].to;
            if(v==a[k])
                continue;
            if(d[v]>0)
            {
                if(d[u]+1==d[v])
                    cnt[v]++;
            }
            if(d[v]==0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return;
}


int main()
{
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    int u,v;
    tot=0;
    while(m--)
    {
        scanf("%d%d",&u,&v);
        add(v,u);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a[i]);
    }
    d[a[k]]=0;
    int zx=0;
    int zd=0;
    bfs();
    for(int i=2;i<k;i++)
    {
        if(d[a[i]]>d[a[i-1]]-1||cnt[a[i-1]]>=1)
            zd++;
        if(d[a[i]]>d[a[i-1]]-1)
            zx++;
    }
    printf("%d %d\n",zx,zd);
    return 0;
}