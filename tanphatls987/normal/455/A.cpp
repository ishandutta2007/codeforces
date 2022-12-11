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

int tmp,n,h[N]={0};
ll f[N]={0};
int main()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&tmp),h[tmp]++;
    FORD(i,N-2,1) f[i]=max(f[i+1],f[i+2]+1LL*i*h[i]);
    printf("%lld",f[1]);
}