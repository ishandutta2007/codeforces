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

const int N=61;

typedef long long ll;

ll f[61][61]={0};
int n,m,t;
int main()
{
    ll a=1;
    scanf("%d%d%d",&n,&m,&t);
    f[0][0]=1;
    FOR(i,1,max(n,m))
        FOR(j,0,i) f[i][j]=f[i-1][j-1]+f[i-1][j];
    //FOR(i,1,max(n,m)) {FOR(j,0,i) printf("%I64d ",f[i][j]);ENDL;}
    ll ans=0;
    REP(i,4,t) ans+=f[n][i]*f[m][t-i];
    printf("%I64d",ans);
}