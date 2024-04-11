#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,w,a[N];
int main(){
    scanf("%d%d",&n,&w);
    FOR(i,1,n<<1) scanf("%d",a+i);
    sort(a+1,a+n*2+1);
    ll ans=min(min(2LL*w,6LL*a[1]*n),3LL*a[n+1]*n);
    printf("%.10f",(ans+.0)/2);
}