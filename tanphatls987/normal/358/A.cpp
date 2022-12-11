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

const int N=1001;

typedef long long ll;

int a[N],n;
void prepare()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
}
int main()
{
    prepare();
    REP(i,1,n-1)
    {
        int l1=min(a[i],a[i+1]),r1=max(a[i],a[i+1]);
        REP(j,i+1,n)
        {
            int l2=min(a[j],a[j+1]),r2=max(a[j],a[j+1]);
            if ((l1<l2&&l2<r1&&r2>r1)||(l2<l1&&l1<r2&&r1>r2)) {printf("yes");return 0;}
        }
    }
    printf("no");
}