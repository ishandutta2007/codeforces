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

const int N=200010;

typedef long long ll;

int a[N],n;
void prepare()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
}
void solve()
{
    printf("%d ",a[n]-a[1]);
    int l=1,r=n;
    while (a[l+1]==a[l])l++;
    while (a[r-1]==a[r]) r--;
    if (a[1]==a[n]) printf("%lld",(1LL*n*(n-1))/2);
    else printf("%lld",1LL*l*(n-r+1));
}
int main()
{
    prepare();
    solve();
}