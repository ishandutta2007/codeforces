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

const int N=3010;

typedef long long ll;

int n,a[3][N],f[N][2];
void prepare()
{
    scanf("%d",&n);
    FOR(i,0,2) FOR(j,1,n) scanf("%d",&a[i][j]);
}
void solve()
{
    f[1][1]=a[1][1];
    f[1][0]=a[0][1];
    FOR(i,2,n)
    {
        f[i][0]=max(f[i-1][1]+a[0][i],f[i-1][0]+a[1][i]);
        f[i][1]=max(f[i-1][0]+a[2][i],f[i-1][1]+a[1][i]);
    }
    //FOR(i,1,n) printf("%d %d\n",f[i][0],f[i][1]);
    printf("%d",f[n][0]);
}
int main()
{
    prepare();
    solve();
}