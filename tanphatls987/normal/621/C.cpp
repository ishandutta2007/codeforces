#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e5+10;

int n,pri;
ii a[N];
double prob[N];
void prepare(){
    scanf("%d%d",&n,&pri);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    a[n+1]=a[1];
    FOR(i,1,n+1) prob[i]=(a[i].Y/pri-(a[i].X-1)/pri+.0)/(a[i].Y-a[i].X+1);
//    FOR(i,1,n) printf("%.6f\n",prob[i]);
}
double solve(){
    double ans=0;
    FOR(i,1,n) ans+=2*prob[i];
    FOR(i,1,n) ans-=prob[i]*prob[i+1];
    return ans*2000;
}
int main(){
    prepare();
    printf("%.12f\n",solve());
}