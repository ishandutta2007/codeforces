#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e16;
const int MOD=1e9+7;
const double PI=atan(1)*4;
const int N=1e5+10;

ll sqr(ll x){
    return x*x;
}
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
ll sqrmodule(ii a){
    return sqr(a.X)+sqr(a.Y);
}
ll operator %(ii a,ii b){
    return 1LL*a.X*b.Y-1LL*a.Y*b.X;
}
ii p[N];
int n;
double solve(){
    ll ma=0;
    double mi=inf;
    p[n+1]=p[1];
//    FOR(i,1,n+1) cout<<p[i].X<<" "<<p[i].Y<<'\n';
    FOR(i,1,n){
        ll cur=sqrmodule(p[0]-p[i]);
        ma=max(ma,cur);
        mi=min(mi,sqrt(cur));
        ll lena=sqrmodule(p[i]-p[0]),lenb=sqrmodule(p[i+1]-p[0]),lenc=(sqrmodule(p[i]-p[i+1]));
        if (lena>lenb) swap(lena,lenb);
        if (lena+lenc>lenb){
            mi=min(mi,abs((p[i]-p[0])%(p[i+1]-p[0]))/sqrt(lenc));
//            printf("%d %lld %.6f %.6f\n",i,abs((p[i]-p[0])%(p[i+1]-p[0])),(sqrt(sqrmodule(p[i+1]-p[i]))),abs((p[i]-p[0])%(p[i+1]-p[0]))/(sqrt(sqrmodule(p[i+1]-p[i]))));
        }
    }
//    printf("%.6f\n",mi);
    return PI*(ma-mi*mi);
}
int main(){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d%d",&p[i].X,&p[i].Y);
    printf("%.12f",solve());
}