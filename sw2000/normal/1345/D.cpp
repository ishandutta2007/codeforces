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
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

char mp[1010][1010];
int n,m,wx[4]={1,-1,0,0},wy[4]={0,0,1,-1};

int solve()
{
    bool f1=0,f2=0;
    for(int i=1;i<=n;i++)
    {
        bool f=0;
        for(int j=1;j<=m;j++)if(mp[i][j]=='#')
        {
            if(f==1&&mp[i][j-1]=='.')return 1;
            f=1;
        }
        if(!f)f1=1;
    }
    for(int j=1;j<=m;j++)
    {
        bool f=0;
        for(int i=1;i<=n;i++)if(mp[i][j]=='#')
        {
            if(f&&mp[i-1][j]=='.')return 1;
            f=1;
        }
        if(!f)f2=1;
    }
    if(f1^f2)return 1;
    return 0;
}

void dfs(int i,int j)
{
    mp[i][j]='.';
    for(int k=0;k<4;k++)
    {
        int x=i+wx[k],y=j+wy[k];
        if(mp[x][y]=='#')dfs(x,y);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
    if(solve())
    {
        puts("-1");
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)if(mp[i][j]=='#')
        {
            dfs(i,j);
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}