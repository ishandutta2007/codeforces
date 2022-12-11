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

const int N=1010;

typedef long long ll;

int pos[5][N]={0},a[N]={0},d[N]={0},n,k,v;
void prepare()
{
    scanf("%d%d",&n,&k);
    k--;
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,k)
        FOR(j,1,n)
        {
            scanf("%d",&v);
            pos[i][v]=j;
        }
}
void solve()
{
    FOR(i,1,n)
        REP(j,0,i)
    {
        int ok=1;
        FOR(l,1,k) if (pos[l][a[j]]>pos[l][a[i]]) ok=0;
        if (ok) d[i]=max(d[i],d[j]+1);
    }
    //FOR(i,1,n) printf("%d ",d[i]);
    printf("%d",*max_element(d+1,d+n+1));
}
int main()
{
    prepare();
    solve();
}