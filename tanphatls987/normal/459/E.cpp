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

const int N=300010;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
iii a[N];
int f[N],n,m;

void prepare()
{
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d%d",&a[i].Y.X,&a[i].Y.Y,&a[i].X);
    sort(a+1,a+m+1);
}
/*
int binsearch(int part,int v)
{
    int l=0;r=l+f[part].size()-1;
    while (l<=r)
    {
        int m=(l+r)>>1;
        if (f[part][m].X>=v) r=m-1;else l=m+1;
    }
    return l;
}*/
void solve()
{
    FOR(i,1,m)
    {
        vector <ii> change;
        int j=i;
        while (a[j].X==a[i].X) {change.push_back(ii(a[j].Y.Y,max(f[a[j].Y.X]+1,f[a[j].Y.Y])));j++;}
        REP(k,0,change.size()) f[change[k].X]=max(f[change[k].X],change[k].Y);
        i=j-1;
    }
    printf("%d",*max_element(f+1,f+n+1));
}
int main()
{
    prepare();
    solve();
}