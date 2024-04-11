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

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=3e5+10;

ii a[N];
int n,h[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i].X);
    FOR(i,1,n) a[i].Y=i;
    sort(a+1,a+n+1);
}
void solve(){
    int rate=0;
    FOR(i,1,n){
        rate=max(rate+1,a[i].X);
        h[a[i].Y]=rate;
    }
    FOR(i,1,n) printf("%d ",h[i]);
}
int main()
{
    prepare();
    solve();
}