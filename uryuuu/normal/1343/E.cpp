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
const int maxn=400010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll p[maxn],s[maxn];

struct node
{
    int to,nxt;
}e[maxn<<1];
int head[maxn],tot;

void add(int u,int v)
{
    e[tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

void dfs(int u,int fa)
{
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
    }
    return;
}

int da[maxn],db[maxn],dc[maxn];
int n,m,a,b,c;

void bfs1()
{
    queue<int>q;
    q.push(a);
    int u,v;
    da[a]=0;
    while(q.size())
    {
        u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            v=e[i].to;
            if(da[v]!=-1)
                continue;
            da[v]=da[u]+1;
            q.push(v);
        }
    }
}

void bfs2()
{
    queue<int>q;
    q.push(b);
    int u,v;
    db[b]=0;
    while(q.size())
    {
        u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            v=e[i].to;
            if(db[v]!=-1)
                continue;
            db[v]=db[u]+1;
            q.push(v);
        }
    }
}

void bfs3()
{
    queue<int>q;
    q.push(c);
    int u,v;
    dc[c]=0;
    while(q.size())
    {
        u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            v=e[i].to;
            if(dc[v]!=-1)
                continue;
            dc[v]=dc[u]+1;
            q.push(v);
        }
    }
}


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b>>c;
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        s[0]=0;
        for(int i=1;i<=m;i++)
        {
            s[i]=1ll*s[i-1]+1ll*p[i];
        }
        int u,v;
        for(int i=1;i<=n;i++)
        {
            head[i]=-1;
            da[i]=-1;
            db[i]=-1;
            dc[i]=-1;
        }
        tot=0;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        bfs1();
        bfs2();
        bfs3();
        ll zx=2e18;
        for(int i=1;i<=n;i++)
        {
            ll d=db[i];
            ll dd=da[i]+dc[i]+d;
            if(dd>m)
                continue;
            zx=min(zx,1ll*s[dd]+1ll*s[d]);
        }
        cout<<zx<<endl;
    }
    
    return 0;
}