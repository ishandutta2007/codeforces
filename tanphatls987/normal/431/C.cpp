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

const int N=101;

typedef long long ll;

int n,k,d,f[N][N]={0};
int solve()
{
    f[0][0]=1;
    FOR(i,1,n)
    {
        FOR(j,1,min(i,d-1)) f[i][0]=(f[i][0]+f[i-j][0])%MOD;
        FOR(j,1,min(i,k)) f[i][1]=(f[i][1]+f[i-j][1])%MOD;
        FOR(j,d,min(i,k)) f[i][1]=(f[i][1]+f[i-j][0])%MOD;
    }
    printf("%d",f[n][1]);
}
int main()
{
    cin>>n>>k>>d;
    solve();
}