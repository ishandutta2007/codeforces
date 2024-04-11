#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const double PI=3.1415926535897,eps=1e-8;
const int N=20;

int L,R,n,cord[N][2],ang[N];
double f[1<<N];
void prepare(){
    scanf("%d%d%d",&n,&L,&R);
    REP(i,0,n) scanf("%d%d%d",cord[i],cord[i]+1,ang+i);
}
double cal(double x,int sel){
    double rad=ang[sel]*PI/180.0+atan((x-cord[sel][0]+.0)/cord[sel][1]);
//    printf("%.6f %d %.6f %.6f\n",x,sel,rad,atan((cord[sel][1]+.0)/(R-cord[sel][0])));
    if (rad>atan((R-cord[sel][0]+.0)/cord[sel][1])) return R;
    return cord[sel][0]+(cord[sel][1]+.0)*tan(rad);
}
double solve(){
  
    REP(i,0,1<<n){
        f[i]=L;
        REP(j,0,n) if (i&(1<<j)) f[i]=max(f[i],cal(f[i^(1<<j)],j));
    }
//    REP(i,0,1<<n) printf("%d %.6f\n",i,f[i]);
    return f[(1<<n)-1]-L;
}
int main(){
    prepare();
    printf("%.6f",solve());
}