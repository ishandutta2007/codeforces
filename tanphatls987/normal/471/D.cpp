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
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9+10;
const int MOD=1e9+7;
const int N=2e5+10;

int f[N],a[N],b[N],n,m;
int failure_func()
{
    f[0]=f[1]=0;
    FOR(i,2,m){
        int r=f[i-1];
        while (b[r+1]-b[r]!=b[i]-b[i-1]&&r>1) r=f[r];
        if (b[r+1]-b[r]==b[i]-b[i-1]) f[i]=r+1;
        f[i]=max(f[i],1);
    }
    //FOR(i,1,m) printf("%d ",f[i]);
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,m) scanf("%d",&b[i]);
    b[0]=-inf;
    failure_func();
}
void solve()
{
    int j=0,ans=0;
    FOR(i,1,n){
        while (j&&a[i]-a[i-1]!=b[j+1]-b[j]) j=f[j];
        if (j==0) j=1;else if (a[i]-a[i-1]==b[j+1]-b[j]) j++;
        if (j==m) ans++,j=f[j];
        //printf("%d %d\n",i,j);
    }
    cout<<ans;
}
int main()
{
    prepare();
    solve();
}