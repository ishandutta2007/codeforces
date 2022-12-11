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
#define inf 1000010

const int N=1010;

typedef long long ll;

int n,m,x,y,a[N]={0},f[N][2]={0};
char s[N];
void prepare()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    FOR(i,1,n)
    {
        scanf("\n%s",s);
        FOR(j,1,m) if (s[j-1]=='.') a[j]++;
    }
    FOR(i,2,m) a[i]+=a[i-1];
}
void solve()
{
    FOR(i,1,m) f[i][0]=f[i][1]=inf;
    FOR(i,x,m)
    {
        FOR(j,x,min(i,y)) f[i][1]=min(f[i][1],f[i-j][0]+a[i]-a[i-j]);
        FOR(j,x,min(i,y)) f[i][0]=min(f[i][0],f[i-j][1]+j*n-a[i]+a[i-j]);
    }
    printf("%d",min(f[m][1],f[m][0]));
}
int main()
{
    prepare();
    solve();
}