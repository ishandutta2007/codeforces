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

const int N=100010;

typedef long long ll;
typedef pair<int,int> ii;

int n,k,a[N];
ll h[N];
ii ans;
void prepare()
{
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    FOR(i,1,n) h[i]=h[i-1]+a[i];
    //FOR(i,1,n) printf("%lld ",h[i]);
}
int solve()
{
    int j=1;
    ans=ii(1,a[1]);
    FOR(i,1,n)
    {
       while (1LL*(i-j+1)*a[i]-h[i]+h[j-1]>k) j++;
       if (i-j+1>ans.X) ans=ii(i-j+1,a[i]);
    }
    printf("%d %d",ans.X,ans.Y);
}
int main()
{
    prepare();
    solve();
}