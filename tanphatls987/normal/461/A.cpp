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

const int N=300010;

typedef long long ll;

int a[N],n;
ll s[N];
int main()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    FORD(i,n,1) s[i]=s[i+1]+a[i];
    ll ans=0;
    FOR(i,0,n-1) ans+=a[i]+s[i+1];
    printf("%lld",ans);
}