#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("509d.inp","r",stdin)
#define OUTPUT freopen("509d.out","w",stdout)
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
const int N=1e2+10;

int n,m,a[N][N];
ll d[N],c[N];
int main(){
    scanf("%d%d",&n,&m);
    REP(i,0,n)
        REP(j,0,m) scanf("%d",&a[i][j]);
    REP(i,0,m) d[i]=a[0][i];
    REP(i,0,n) c[i]=a[i][0]-d[0];
    //REP(i,0,n) printf("%lld ",c[i]);ENDL;
    //REP(i,0,m) printf("%lld ",d[i]);ENDL;
    ll mod=0;
    bool ok=true;
    REP(i,0,n)
        REP(j,0,m) if (c[i]+d[j]-a[i][j]) ok=false;
    if (!ok) {
        REP(i,0,n)
            REP(j,0,m) mod=__gcd(mod,ll(abs(c[i]+d[j]-a[i][j])));
        ok=true;
        REP(i,0,n)
            REP(j,0,m) if (mod<=a[i][j]) ok=false;
    }else mod=MOD;
    if (!ok) {printf("NO");return 0;}
    printf("YES\n%lld\n",mod);
    REP(i,0,n) while (c[i]<0) c[i]+=mod;
    REP(i,0,n) printf("%lld ",c[i]);ENDL;
    REP(i,0,m) printf("%lld ",d[i]);
}