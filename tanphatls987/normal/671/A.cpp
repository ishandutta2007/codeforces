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

const int inf=1e9;
const ll linf=1e15;
const int MOD=1e9+7;
const int N=1e5+10;

int n;
ii a[N];
ii sa,sb,st;
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
double len(ii a){
    return sqrt(1LL*a.X*a.X+1LL*a.Y*a.Y);
}
void prepare(){
    scanf("%d%d%d%d%d%d",&sa.X,&sa.Y,&sb.X,&sb.Y,&st.X,&st.Y);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
}
double pot(double a,double b){
    if (max(a,b)<0) return max(a,b);
    return max(a,.0)+max(b,.0);
}
double solve(){
    double ans=0;
    FOR(i,1,n) ans+=2*len(a[i]-st);
    double fa1,fa2,fb1,fb2;
    fa1=fa2=fb1=fb2=-linf;
    int ia1,ia2,ib1,ib2;
    FOR(i,1,n){
        if (maximize(fa2,len(a[i]-st)-len(a[i]-sa))) ia2=i;
        if (fa2>fa1){
            swap(fa2,fa1);
            swap(ia2,ia1);
        }
    }
    FOR(i,1,n){
        if (maximize(fb2,len(a[i]-st)-len(a[i]-sb))) ib2=i;
        if (fb2>fb1){
            swap(fb2,fb1);
            swap(ib2,ib1);
        }
    }
//    cout<<ans<<'\n';
//    cout<<fa1<<" "<<fb1<<'\n';
    if (ia1!=ib1) ans-=pot(fa1,fb1);
    else ans-=max(pot(fa1,fb2),pot(fb1,fa2));
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    printf("%.12f",solve());
}