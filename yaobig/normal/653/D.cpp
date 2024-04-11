#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct edge
{
    int u,v,c,C,next;
}e[maxn*2+5];
int p[maxn+5],d[maxn+5],cnt,src,sink;
int cur[maxn+5];
void add(int u,int v,int c)
{
    e[cnt].u=u;e[cnt].v=v;e[cnt].C=c;
    e[cnt].next=p[u]; p[u]=cnt++;
    e[cnt].u=v;e[cnt].v=u;e[cnt].C=0;
    e[cnt].next=p[v]; p[v]=cnt++;
}
int bfs()
{
    memset(d,-1,sizeof d);
    d[src]=0;
    queue<int> q;
    q.push(src);
    while(q.empty()==0)
    {
        int u=q.front(); q.pop();
        for(int i=p[u];i!=-1;i=e[i].next)
        {
            int v=e[i].v;
            if(e[i].c && d[v]==-1)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[sink]!=-1;
}
int dfs(int now,int f)
{
    if(now==sink) return f;
    int r=0;
    for(int i=cur[now];i!=-1 && r<f;i=e[i].next)
    {
        int v=e[i].v;
        if(e[i].c && d[v]==d[now]+1)
        {
            int tmp=min(f-r,e[i].c);
            int x=dfs(v,tmp);
            r+=x;
            e[i].c-=x;
            e[i^1].c+=x;
            cur[now]=i;
        }
    }
    if(r<f) d[now]=-2;
    return r;
}
int n,m,x;
int MF()
{
    int res=0;
    while(bfs())
    {
        rep(i,1,n) cur[i]=p[i];
        res+=dfs(src,inf);
    }
    //printf("????? %d\n",res);
    return res;
}

bool check(db w)
{
    //printf("?? %f\n",w);
    rep(i,0,cnt-1)
    {
        if(w==0) e[i].c=x;
        else
        {
            db t=e[i].C/w;
            if(t>x) t=x;
            e[i].c=floor(t);
        }
    }
    return MF()>=x;
}

int main()
{
    scanf("%d%d%d",&n,&m,&x);
    rep(i,1,n) p[i]=-1;
    rep(i,1,m)
    {
        int x,y,C; scanf("%d%d%d",&x,&y,&C);
        add(x,y,C);
    }
    src=1; sink=n;
    db l=0,r=1000000;
    rep(i,1,100)
    {
        db mid=(l+r)/2;
        if(check(mid)==0) r=mid;
        else l=mid;
    }
    printf("%.10f\n",(l+r)/2*x);
    return 0;
}