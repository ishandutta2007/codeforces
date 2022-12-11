#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=18;

int n;
double win[N][N],f[1<<N][N];
void prepare(){
    scanf("%d",&n);
    REP(i,0,n)
        REP(j,0,n) scanf("%lf",win[i]+j);
}
double solve(){
    f[(1<<n)-1][0]=1;
    FORD(i,(1<<n)-2,1)
        REP(en,0,n) if (i&(1<<en))
            REP(cas,0,n) if (!(i&(1<<cas))) {
                int li=i|(1<<cas);
                f[i][en]=max(f[i][en],win[en][cas]*f[li][en]+win[cas][en]*f[li][cas]);
            }
    double ans=0;
    REP(i,0,n) ans=max(ans,f[1<<i][i]);
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    printf("%.6f",solve());
}