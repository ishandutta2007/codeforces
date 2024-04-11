#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=0;
const long double PI=4*atan(1);

ll sqr(ll x){return x*x;}
ii a[2];
int r[2];
long double f[2],angle[2];
double solve(){
    if (r[0]<r[1]){
        swap(r[0],r[1]);
        swap(a[0],a[1]);
    }
    ll sqdis=sqr(a[0].X-a[1].X)+sqr(a[0].Y-a[1].Y);
//    cout<<sqdis<<'\n';
    if (sqdis>=1LL*(r[0]+r[1])*(r[0]+r[1])) return .0;
    long double dis=sqrt(sqdis);
    if (dis+r[1]<=r[0]) return PI*r[1]*r[1];
//    printf("%.6f\n",ans);
    FOR(i,0,1){
        long double rat=(sqdis+sqr(r[i])-sqr(r[i^1])+.0)/(2*dis*r[i]);
        angle[i]=acos(rat)*2;
        f[i]=(angle[i]/2-sin(angle[i])/2)*r[i]*r[i];
//        printf("%.15lf\n",f[i]);
    }
    return f[0]+f[1];
}
int main(){
    FOR(i,0,1) cin>>a[i].X>>a[i].Y>>r[i];
    printf("%.15f",solve());
}