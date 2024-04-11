#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

pii to[maxn+5];
vi e[maxn+5];
int n,m;

int deg[maxn+5],q[maxn+5];

bool check(int x)
{
    rep(i,1,n) deg[i]=0;
    rep(i,1,n)
    {
        for(int id: e[i])
        {
            int v=to[id].FI;
            int w=to[id].SE;
            if(w<=x) continue;
            deg[v]++;
        }
    }
    int rear=-1;
    rep(i,1,n) if(deg[i]==0) q[++rear]=i;
    rep(front,0,rear)
    {
        int now=q[front];
        for(int id: e[now])
        {
            int v=to[id].FI;
            int w=to[id].SE;
            if(w<=x) continue;
            if(--deg[v]==0)
            {
                q[++rear]=v;
            }
        }
    }
    return rear==n-1;
}

int lb(int l,int r)
{
    r++;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
int rk[maxn+5];

int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        to[i]=mp(y,w);
        e[x].pb(i);
    }
    int ans=lb(0,1000000000);
    check(ans);
    rep(i,0,n-1) rk[q[i]]=i+1;
    vi rev;
    rep(i,1,n)
    {
        for(int id: e[i])
        {
            int v=to[id].FI;
            int w=to[id].SE;
            if(w>ans) continue;
            if(rk[v]<rk[i]) rev.pb(id);
        }
    }
    int N=rev.size();
    printf("%d %d\n",ans,N);
    rep(i,0,N-1) printf("%d%c",rev[i]," \n"[i==N-1]);
    return 0;
}