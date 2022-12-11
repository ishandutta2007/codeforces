#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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

int n,ans[N],a[N],p[N],per[N];
ll full,cf,cl,m,L[N],R[N];
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
bool comp(int x,int y){
    return a[x]<a[y];
}
void prepare(){
    scanf("%d%lld%lld%lld%lld",&n,&full,&cf,&cl,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) per[i]=i;
    sort(per+1,per+n+1,comp);
//    FOR(i,1,n) cout<<per[i]<<" \n"[i==n];
    FOR(i,1,n) p[i]=a[per[i]];
    FOR(i,1,n) L[i]=L[i-1]+p[i];
    FORD(i,n,1) R[i]=R[i+1]+p[i];
}
ll cal(int sel,int type){
    ll rem=m-(full*(n-sel+1)-R[sel]);
    if (rem<0) return -1;
    int cL=0,cR=full;
    while (cL<=cR){
        int mid=(cL+cR)/2;
        int idx=lower_bound(p+1,p+sel,mid)-p-1;
        if (1LL*idx*mid-L[idx]<=rem) cL=mid+1;
        else cR=mid-1;
    }
//    cout<<sel<<" "<<rem<<" "<<cR<<'\n';
    if (type==1){
        FORD(i,n,sel) ans[per[i]]=full;
        REP(i,1,sel) ans[per[i]]=max(p[i],cR);
    }
    return cf*(n-sel+1)+cl*cR;
}
void solve(){
    ll answ=-1,sel=-1;
    FOR(i,1,n+1) if (maximize(answ,cal(i,0))) sel=i;
    ///
    cal(sel,1);
    printf("%lld\n",answ);
    FOR(i,1,n) printf("%d ",ans[i]);
}
int main(){
    prepare();
    solve();
}