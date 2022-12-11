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
#define inf 2000000000

const int N=100001;

typedef long long ll;
typedef pair<int,ll> ii;

pair<int,int> a[N];
ii s[N];
int n,top,bot;
int prepare()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i].X);
    FOR(i,1,n) scanf("%d",&a[i].Y);
    //FOR(i,1,n) printf("%d %d\n",a[i].X,a[i].Y);
}
bool leftside(ii x,ii y,ii z)
{
    return (y.Y-x.Y)/(0.+x.X-y.X)<=(z.Y-x.Y)/(0.+x.X-z.X);
}
ll calc(ii line,int x){
   return 1LL*x*line.X+line.Y;
}
void push(ii nline)
{
    while (bot<top&&leftside(s[top],nline,s[top-1])) top--;
    s[++top]=nline;
}
int solve()
{
    s[0]=ii(a[1].Y,0);
    top=0;bot=0;
    FOR(i,2,n)
    {
        while (bot<top&&calc(s[bot],a[i].X)>=calc(s[bot+1],a[i].X)) bot++;
        ii nline=ii(a[i].Y,calc(s[bot],a[i].X));
        push(nline);
        //printf("%d\n",i);
        //FOR(j,bot,top) printf("%d %I64d %d\n",s[j].X.X,s[j].X.Y,s[j].Y);
    }
    printf("%I64d",s[top].Y);
}
int main()
{
    prepare();
    solve();
}