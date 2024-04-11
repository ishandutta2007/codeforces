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
#define inf 1000000

const int MOD=1000000007;
const int N=5010;

typedef long long ll;

int a[N],b[N],c[N],n,m,k,x,y;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",&b[i]);
    scanf("%d",&k);
    FOR(i,1,k) scanf("%d",&c[i]);
    scanf("%d%d",&x,&y);
    sort(a+1,a+n+1);
    sort(c+1,c+k+1);
}
void solve(){
    double ans=0;
    FOR(i,1,m) ans=max(ans,sqrt((0.+1LL*a[n]*a[n]*b[i]*y)/(c[1]*x+b[i]*y)));
    printf("%.12lf",ans);
}
int main(){
    prepare();
    solve();
}