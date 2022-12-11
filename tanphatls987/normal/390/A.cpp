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

const int N=101;

typedef long long ll;

int n,x,y,h[N]={0},v[N]={0};
int prepare()
{
    scanf("%d",&n);
    FOR(i,1,n)
    {
        scanf("%d%d",&x,&y);
        h[x]++;
        v[y]++;
    }
    int ansa=0,ansb=0;
    REP(i,0,N) ansa+=(h[i]>0);
    REP(i,0,N) ansb+=(v[i]>0);
    printf("%d",min(ansa,ansb));
}
int main()
{
    prepare();
}