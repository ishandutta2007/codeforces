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
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

pii wk[4]={{1,0},{-1,0},{0,1},{0,-1}};
char to[4]={'U','D','L','R'};
int n;
pii boa[maxn][maxn];
char ans[maxn][maxn];

void dfs(pii a)
{
    for(int i=0;i<4;i++)
    {
        int x=a.x+wk[i].x;
        int y=a.y+wk[i].y;
        if(ans[x][y]==0&&boa[a.x][a.y]==boa[x][y])
        {
            ans[x][y]=to[i];
            dfs({x,y});
        }
    }
}

bool solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(boa[i][j].x==i&&boa[i][j].y==j)
            {
                ans[i][j]='X';
                dfs(boa[i][j]);
            }
            if(boa[i][j].x==-1)
            {
                bool flag=0;
                for(int k=0;k<4;k++)
                {
                    if(boa[i+wk[k].x][j+wk[k].y].x==-1)
                    {
                        ans[i][j]==to[k^1];
                        dfs({i,j});
                        flag=1;
                    }
                }
                if(!flag)return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!ans[i][j])return 0;
        }
    }
    return 1;
}

int main()
{
    // freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        ans[0][i]=1;
        ans[i][0]=1;
        ans[n+1][i]=1;
        ans[i][n+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d%d",&boa[i][j].x,&boa[i][j].y);
        }
    }
    if(!solve())puts("INVALID");
    else 
    {
        puts("VALID");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)printf("%c",ans[i][j]);
            puts("");
        }
    }
    return 0;
}