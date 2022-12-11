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

const ll linf=1e17;
const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,n1,n2;
ii a[N];
ll p[N],gpo[2][N],gne[2][N];
ll sqr(ll x){
    return x*x;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
}
bool check(ll mid){
    ll len=ll(sqrt(mid));
    for(int i=n1,j=n1;i;i--){
        while (j&&p[j]+len>=p[i]) j--;
        ll chiy=max(gpo[1][i+1],gpo[0][j]),cloy=min(gne[1][i+1],gne[0][j]);
        if (sqr(chiy-cloy)<=mid&&sqr(p[i]-p[j+1])<=mid&&sqr(max(p[i],-p[j+1]))+sqr(max(chiy,-cloy))<=mid) return 1;
    }
    return 0;
}
ll cal(){
    FOR(i,1,n) p[i]=a[i].X;
    sort(p+1,p+n+1);
    n1=unique(p+1,p+n+1)-p-1;
    memset(gpo,0,sizeof(gpo));
    memset(gne,0,sizeof(gne));
    FOR(i,1,n){
        int idx=lower_bound(p+1,p+n1+1,a[i].X)-p;
        gpo[0][idx]=max(gpo[0][idx],1LL*a[i].Y);
        gne[0][idx]=min(gne[0][idx],1LL*a[i].Y);
    }
    FOR(i,1,n1) {
        gpo[1][i]=gpo[0][i];
        gne[1][i]=gne[0][i];
    }
    FOR(i,1,n1) {
        gpo[0][i]=max(gpo[0][i],gpo[0][i-1]);
        gne[0][i]=min(gne[0][i],gne[0][i-1]);
    }
    FORD(i,n1,1) {
        gpo[1][i]=max(gpo[1][i],gpo[1][i+1]);
        gne[1][i]=min(gne[1][i],gne[1][i+1]);
    }
//    FOR(i,1,n) cout<<p[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<gpo[0][i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<gne[0][i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<gpo[1][i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<gne[1][i]<<" \n"[i==n];
    ll L=0,R=linf;
    while (L<=R){
        ll mid=(L+R)/2;
        if (check(mid)) R=mid-1;
        else L=mid+1;
    }
    return min(L,sqr(min(gpo[0][n1]-gne[0][n1],p[n1]-p[1])));
}
ll solve(){
    ll ans=linf;
    FOR(pha,0,1){
        FOR(i,1,n) swap(a[i].X,a[i].Y);
        ans=min(ans,cal());
        FOR(i,1,n) a[i].X*=-1;
        ans=min(ans,cal());
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}