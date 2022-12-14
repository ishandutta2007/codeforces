#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

char tmp[1010];
int n,m,t,wx[4]={1,-1,0,0},wy[4]={0,0,1,-1};
int mp[1010][1010],ans[1010][1010];

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&t);
    memset(mp,-1,sizeof(mp));
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        scanf("%s",tmp);
//        cout<<tmp<<endl;
        for(int j=0;j<m;j++)
        {
            mp[i][j+1]=tmp[j]-'0';
        }
    }
    queue<pii>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)if(mp[i][j]==mp[i+wx[k]][j+wy[k]])
            {
                ans[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        pii u=q.front();q.pop();
        for(int k=0;k<4;k++)
        {
            int nx=u.x+wx[k],ny=u.y+wy[k];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&ans[nx][ny]==-1)
            {
                ans[nx][ny]=ans[u.x][u.y]+1;
                q.push({nx,ny});
            }
        }
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            cout<<ans[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    while(t--)
    {
        int a,b;ll c;scanf("%d%d%lld",&a,&b,&c);
        int d;
        if(ans[a][b]==-1||c<=ans[a][b]||(c-ans[a][b])%2==0)d=mp[a][b];
        else d=mp[a][b]^1;
        printf("%d\n",d);
    }
    return 0;
}