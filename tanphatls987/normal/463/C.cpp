#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=2010;

typedef long long ll;
typedef pair<int,int> ii;

int n,a[N][N]={0};
ll f[N][N][2]={0},ans[2];
ii t[2];
void prepare()
{
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
    FORD(i,n,1) FORD(j,n,1) f[i][j][1]=f[i+1][j+1][1]+a[i][j];
    FOR(i,1,n) FORD(j,n,1) f[i][j][0]=f[i-1][j+1][0]+a[i][j];
}
void solve()
{
    ans[0]=ans[1]=-1;
    FOR(i,1,n) FOR(j,1,n)
    {
        int xa=min(i+j-1,n),ya=i+j-xa;
        int xb=max(i-j+1,1),yb=j-(i-xb);
        //printf("%d %d %d %d %d %d %lld %lld\n",i,j,xa,ya,xb,yb,f[xa][ya][0],f[xb][yb][1]);
        if (ans[(j+i)%2]<f[xa][ya][0]+f[xb][yb][1]-a[i][j])
        {
            ans[(j+i)%2]=f[xa][ya][0]+f[xb][yb][1]-a[i][j];
            t[(j+i)%2]=ii(i,j);
        }
    }
    printf("%lld\n%d %d %d %d",ans[1]+ans[0],t[0].X,t[0].Y,t[1].X,t[1].Y);
}
int main()
{
    prepare();
    solve();
}