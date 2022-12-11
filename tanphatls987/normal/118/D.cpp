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
#define MOD 100000000
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=102;
int p[2*N][N][2][11]={0},n0,n1,k0,k1;

typedef long long ll;

int solve()
{
    p[0][0][1][0]=p[0][0][0][0]=1;
    FOR(i,1,n0+n1)
        FOR(j,0,min(i,n0)) if (i-j<=n1)
        {
            FOR(k,0,min(j,k0-1)) p[i][j][1][0]=(p[i][j][1][0]+p[i-1][j-1][0][k])%MOD;
            FOR(k,1,min(i-j,k1)) p[i][j][1][k]=(p[i][j][1][k]+p[i-1][j][1][k-1])%MOD;
            FOR(k,0,min(i-j,k1-1)) p[i][j][0][0]=(p[i][j][0][0]+p[i-1][j][1][k])%MOD;
            FOR(k,1,min(j,k0-1)) p[i][j][0][k]=(p[i][j][0][k]+p[i-1][j-1][0][k-1])%MOD;
        }
        /*
    FOR(i,0,n0+n1)
        FOR(j,0,n0)
        {
            FOR(k,0,k0) printf("p[%d][%d][0][%d]=%d\n",i,j,k,p[i][j][0][k]);
            FOR(k,0,k1) printf("p[%d][%d][1][%d]=%d\n",i,j,k,p[i][j][1][k]);
        }*/
    printf("%d",(p[n0+n1][n0][1][0]+p[n0+n1][n0][0][0])%MOD);
}
int main()
{
    cin>>n0>>n1>>k0>>k1;
    solve();
}