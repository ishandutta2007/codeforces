#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 2000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int mov[4][2]={-1,0,1,0,0,-1,0,1};
const int cost[4]={0,0,1,1};
char s[maxn+5][maxn+5];

int dis[maxn+5][maxn+5];
bool mark[maxn+5][maxn+5];
struct node
{
    int x,y,d;
    node(){}
    node(int a,int b,int c):x(a),y(b),d(c){}
    bool operator <(const node &a) const {return d>a.d;}
};
priority_queue<node> q;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int sx,sy; scanf("%d%d",&sx,&sy);
    int ll,lr; scanf("%d%d",&ll,&lr);
    rep(i,1,n) scanf("%s",s[i]+1);
    memset(dis,63,sizeof dis);
    dis[sx][sy]=0;
    q.push(node(sx,sy,0));
    while(!q.empty())
    {
        node now=q.top();q.pop();
        int x=now.x;
        int y=now.y;
        if(mark[x][y]) continue;
        mark[x][y]=1;
        //printf("! %d %d: %d\n",x,y,dis[x][y]);
        rep(i,0,3)
        {
            int nx=x+mov[i][0];
            int ny=y+mov[i][1];
            int w=cost[i];
            if(s[nx][ny]!='.') continue;
            if(dis[nx][ny]>dis[x][y]+w)
            {
                dis[nx][ny]=dis[x][y]+w;
                q.push(node(nx,ny,dis[nx][ny]));
            }
        }
    }
    int ans=0;
    rep(x,1,n) rep(y,1,m)
    {
        if(dis[x][y]==inf) continue;
        int l=(dis[x][y]+sy-y)>>1;
        int r=(dis[x][y]-sy+y)>>1;
        if(l<=ll && r<=lr) ans++;//,printf("? %d %d\n",x,y);
    }
    printf("%d\n",ans);
    return 0;
}