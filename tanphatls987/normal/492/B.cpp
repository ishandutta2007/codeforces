#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <map>

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
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e3+10;

int n,m,a[N];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
}
int main(){
    prepare();
    ll ans=max(2LL*a[1],2LL*(m-a[n]));
    FOR(i,2,n) ans=max(ans,1LL*(a[i]-a[i-1]));
    printf("%lld",ans/2);
    if (ans%2) printf(".5");
}