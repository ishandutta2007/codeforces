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

const int N=3000;

typedef long long ll;
typedef pair<int,int> ii;

ii a[N];
int n,m,k;
bool comp(ii a,ii b) {if (a.X+a.Y==b.X+b.Y) return a.X<b.X;else return a.X+a.Y<b.X+b.Y;}
void prepare()
{
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) FOR(j,1,m) a[m*(i-1)+j]=ii(i,j);
    sort(a+1,a+m*n+1,comp);
}
void solve()
{
    int ans=0;
    FOR(i,1,k) ans+=a[i].X+a[i].Y-1;
    printf("%d\n",ans);
    FORD(i,k,1)
    {
        FOR(j,1,a[i].X) printf("(%d,1) ",j);
        FOR(j,2,a[i].Y) printf("(%d,%d) ",a[i].X,j);
        ENDL;
    }
}
int main()
{
    prepare();
    solve();
}