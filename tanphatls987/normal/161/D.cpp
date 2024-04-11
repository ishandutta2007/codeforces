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
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=100001;

typedef long long ll;
vector <int> a[N];

int c[N],p[N][501]={0},n,k,x,y;

int prepare()
{
    //INPUT;
    scanf("%d%d",&n,&k);
    REP(i,1,n)
    {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
void DFS(int par,int node)
{
    p[node][0]=1;
    c[node]=0;
    REP(i,0,a[node].size()) if (a[node][i]!=par)
    {
        DFS(node,a[node][i]);
        c[node]+=c[a[node][i]];
        FOR(j,1,k) c[node]+=p[a[node][i]][j-1]*p[node][k-j];
        FOR(j,1,k) p[node][j]+=p[a[node][i]][j-1];
    }
}
int solve()
{
    DFS(0,1);
    printf("%d",c[1]);
}
int main()
{
    prepare();
    solve();
}