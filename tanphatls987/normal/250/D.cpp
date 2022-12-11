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
const int N=1e5+10;

int n,m,xa,xb,a[N],b[N],c[N];
ll sqr(int x){
    return 1LL*x*x;
}
double dist(int xa,int ya,int xb,int yb){
    return sqrt(sqr(xb-xa)+sqr(yb-ya));
}
void prepare(){
    scanf("%d%d%d%d",&n,&m,&xa,&xb);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m) scanf("%d",b+i);
    FOR(i,1,m) scanf("%d",c+i);
}
template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void solve(){
    double ans=1e9;
    int sela=0,selb=0;
    FOR(i,1,m){
        int x=1LL*b[i]*xa/xb,idx=lower_bound(a+1,a+n+1,x)-a;
//        printf("%d %d\n",i,x);
        if (idx<=n&&minimize(ans,c[i]+dist(0,0,xa,a[idx])+dist(xa,a[idx],xb,b[i]))) sela=idx,selb=i;
        if (idx>1&&minimize(ans,c[i]+dist(0,0,xa,a[idx-1])+dist(xa,a[idx-1],xb,b[i]))) sela=idx-1,selb=i;
    }
//    printf("%.6f\n",ans);
    cout<<sela<<" "<<selb;
}
int main(){
    prepare();
    solve();
}