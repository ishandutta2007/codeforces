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

const int N=200010;

typedef long long ll;
vector <int> a[N];
int n,x,y,f[N];
int prepare()
{
    scanf("%d",&n);
    REP(i,1,n)
    {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(-x);
    }
}
void DFS1(int p,int x)
{
    f[x]=0;
    REP(i,0,a[x].size())
    {
        int sel=abs(a[x][i]);
        if (sel==p) continue;
        DFS1(x,sel);
        f[x]+=f[sel];
        if (a[x][i]<0) f[x]++;
    }
}
void DFS2(int p,int x)
{
    REP(i,0,a[x].size())
    {
        int sel=abs(a[x][i]);
        if (sel==p) continue;
        f[sel]=f[x];
        if (a[x][i]<0) f[sel]--;else f[sel]++;
        DFS2(x,sel);
    }
}
void solve()
{
    DFS1(0,1);
    //FOR(i,1,n) printf("%d ",f[i]);
    DFS2(0,1);
    //FOR(i,1,n) printf("%d ",f[i]);
    int ans=*min_element(f+1,f+n+1);
    printf("%d\n",ans);
    FOR(i,1,n) if (f[i]==ans) printf("%d ",i);
}
int main()
{
    prepare();
    solve();
}