#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1500
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int sz[maxn+5];

void dfs(int now,int fa)
{
    sz[now]=1;
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        sz[now]+=sz[v];
    }
}

struct P
{
    int x,y,id;
    P(){}
    P(int a,int b,int c=0):x(a),y(b),id(c){}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
}p[maxn+5];
ll cross(P a,P b) {return 1ll*a.x*b.y-1ll*a.y*b.x;}

int ans[maxn+5];

P o;
bool cmp(P a,P b) {return cross(a-o,b-o)<=0;}

void solve(int now,int fa,int l,int r)
{
    rep(i,l+1,r) if(p[i].y<p[l].y) swap(p[i],p[l]);
    ans[p[l].id]=now;
    o=p[l];
    sort(p+l+1,p+r+1,cmp);
    int c=l+1;
    for(auto v: e[now]) if(v!=fa)
    {
        solve(v,now,c,c+sz[v]-1);
        c+=sz[v];
    }
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n-1) {int x,y; scanf("%d%d",&x,&y); e[x].pb(y); e[y].pb(x);}
    dfs(1,0);
    rep(i,1,n)
    {
        int x,y; scanf("%d%d",&x,&y);
        p[i]=P(x,y,i);
    }
    solve(1,0,1,n);
    rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}