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

int a[N],d[N]={0},h[N],n,k,q,x,y;
char s[N];
int prepare()
{
    scanf("%d%d%d\n%s",&n,&k,&q,s);
    FOR(i,1,n) a[i]=s[i-1]=='1';
    FOR(i,k,n) d[i]=d[i-k]+a[i];
    FOR(i,1,n) h[i]=h[i-1]+a[i];
}
int main()
{
    prepare();
    while (q)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",h[y]-h[x-1]+((y-x+1)/k)-2*(d[y]-d[x-1]));
        q--;
    }
}