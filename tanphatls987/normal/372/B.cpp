#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
//#include <math.h>
#include <deque>
#include <vector>
#include <queue>
#include <stack>

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

const int N=42;

typedef long long ll;

int f[N][N][N][N]={0},h[N][N]={0},a[N][N],n,m,q,x1,x2,y1,y2;
char s[N];
void prepare()
{
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n)
    {
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=s[j-1]-'0';
    }
    FOR(i,1,n) FOR(j,1,m) h[i][j]=h[i-1][j]+h[i][j-1]-h[i-1][j-1]+a[i][j];
}
int check(int x1,int y1,int x2,int y2){
    return (h[x2][y2]+h[x1-1][y1-1]-h[x1-1][y2]-h[x2][y1-1])==0;
}
void solve()
{
    FORD(i1,n,1)
        FORD(j1,m,1)
            FOR(i,i1,n)
                FOR(j,j1,m)
    f[i1][j1][i][j]=check(i1,j1,i,j)+f[i1+1][j1][i][j]+f[i1][j1][i-1][j]+f[i1][j1+1][i][j]+f[i1][j1][i][j-1]-f[i1+1][j1+1][i][j]-f[i1+1][j1][i-1][j]-f[i1+1][j1][i][j-1]-f[i1][j1+1][i-1][j]-f[i1][j1+1][i][j-1]-f[i1][j1][i-1][j-1]+f[i1+1][j1+1][i-1][j]+f[i1+1][j1+1][i][j-1]+f[i1+1][j1][i-1][j-1]+f[i1][j1+1][i-1][j-1]-f[i1+1][j1+1][i-1][j-1];
}
int main()
{
    prepare();
    solve();
    while (q--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",f[x1][y1][x2][y2]);
    }
}