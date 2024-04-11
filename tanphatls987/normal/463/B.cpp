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

int a[N],n;
int main()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    a[0]=0;
    ll ene=0,cost=0;
    FOR(i,0,n-1){
        if (a[i+1]-a[i]>ene){
            cost+=1LL*a[i+1]-a[i]-ene;
            ene=0;
        }else ene-=(a[i+1]-a[i]);
    }
    printf("%lld",cost);
}