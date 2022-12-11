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

const int N=(int) 5*1e5;

typedef long long ll;

int a[N+1],n;
void prepare()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
}
int main()
{
    prepare();
    int ans=n;
    for(int i=n,j=n/2;i>n/2,j>0;i--,j--)
    {
        while (2*a[j]>a[i]&&j>0) j--;
        if (j>0) ans--;
    }
    printf("%d",ans);
}