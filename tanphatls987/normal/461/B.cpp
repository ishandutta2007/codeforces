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

vector <int> a[N];
int n,s[N],x;
ll f[N][2]={0};
void prepare()
{
    scanf("%d",&n);
    REP(i,1,n) scanf("%d",&x),a[x].push_back(i);
    REP(i,0,n) scanf("%d",s+i);
}
void DFS(int x)
{
    f[x][0]=1;f[x][1]=0;
    REP(i,0,a[x].size()){
        DFS(a[x][i]);
        f[x][1]=(f[x][1]*f[a[x][i]][0])%MOD;
        f[x][1]=(f[x][1]+(f[x][0]*f[a[x][i]][1])%MOD)%MOD;
        f[x][0]=(f[x][0]*f[a[x][i]][0])%MOD;
    }
    if (s[x]==0) f[x][0]=(f[x][0]+f[x][1])%MOD;
    else f[x][1]=f[x][0];
}
int main()
{
    prepare();
    DFS(0);
    //FOR(i,0,n-1) printf("%lld %lld\n",f[i][0],f[i][1]);
    printf("%lld",f[0][1]);
}