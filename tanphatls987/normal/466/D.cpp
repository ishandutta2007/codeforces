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

ll f[N][N]={0};
int n,h,a[N];
int main()
{
    scanf("%d%d",&n,&h);
    FOR(i,1,n) scanf("%d",&a[i]);
    f[1][0]=(a[1]==h||a[1]==h-1);
    f[1][1]=(a[1]==h-1);
    FOR(i,2,n){
        int open=h-a[i];
        if (open>0) f[i][open]=f[i-1][open-1];
        f[i][open]=(f[i][open]+f[i-1][open])%MOD;
        open--;
        f[i][open]=((f[i-1][open])+(f[i-1][open+1]*(open+1))%MOD)%MOD;
        if (open>0) f[i][open]=(f[i][open]+(f[i-1][open]*open)%MOD)%MOD;
    }
    cout<<f[n][0];
}