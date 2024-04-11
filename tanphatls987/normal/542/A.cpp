#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e5+10;

priority_queue <ii> q;
int coor[N<<3],b[N<<3],n,m,k,ps[N],pa[N],v[N],L[N<<3],R[N<<3];
ii seg[N],a[N];
bool comps1(int x,int y){return seg[x].Y<seg[y].Y;}
bool comps2(int x,int y){return seg[x].X<seg[y].X;}
bool comps3(int x,int y){return seg[x].Y-seg[x].X<seg[y].Y-seg[y].X;}
bool compa(int x,int y){return a[x].Y<a[y].Y;}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&seg[i].X,&seg[i].Y);
    FOR(i,1,m) scanf("%d%d%d",&a[i].X,&a[i].Y,v+i);
    FOR(i,1,n) ps[i]=i;
    FOR(i,1,m) pa[i]=i;
    sort(ps+1,ps+n+1,comps2);
    sort(pa+1,pa+m+1,compa);
    FOR(i,1,n) coor[i]=seg[i].X,coor[n+i]=seg[i].Y;
    FOR(i,1,m) coor[2*n+i]=a[i].X,coor[2*n+m+i]=a[i].Y;
    sort(coor+1,coor+2*n+2*m+1);
    k=unique(coor+1,coor+2*n+2*m+1)-coor-1;
}
void add(int x,int v){
    while (x){
        if (comps3(b[x],v)) b[x]=v;
        x-=x&-x;
    }
}
int get(int x){
    int tmp=0;
    while (x<=k){
        if (comps3(tmp,b[x])) tmp=b[x];
        x+=x&-x;
    }
    return tmp;
}
bool maximize(ll &x,ll y){
    if (x<y) x=y;else return false;
    return true;
}
void solve(){
    ///maxR for pos
    for(int i=1,j=1;i<=k;i++){
        while (j<=n&&seg[ps[j]].X<=coor[i]) q.push(ii(seg[ps[j]].Y,ps[j])),j++;
        if (!q.empty()) R[i]=q.top().Y;
    }
    while (!q.empty()) q.pop();
    ///minL for pos
    sort(ps+1,ps+n+1,comps1);
    for(int i=k,j=n;i;i--){
        while (j&&seg[ps[j]].Y>=coor[i]) q.push(ii(-seg[ps[j]].X,ps[j])),j--;
        if (!q.empty()) L[i]=q.top().Y;
    }
    ///special segment
//    FOR(i,1,k) printf("%d ",coor[i]);ENDL;
//    FOR(i,1,k) printf("%d ",L[i]);ENDL;
//    FOR(i,1,k) printf("%d ",R[i]);ENDL;
    seg[0]=ii(inf,0);
    ll ans=0;
    int ansa,anss;
    for(int i=1,j=1,i1=1;i<=k;i++){
        while (j<=n&&seg[ps[j]].Y<=coor[i]){
            int x=lower_bound(coor+1,coor+k+1,seg[ps[j]].X)-coor;
            add(x,ps[j++]);
        }
        while (i1<=m&&a[pa[i1]].Y<=coor[i]){
            int idx=pa[i1++];
            ///get idx;
            int cL=lower_bound(coor+1,coor+k+1,a[idx].X)-coor,cR=lower_bound(coor+1,coor+k+1,a[idx].Y)-coor;
            ///cal 3 part
            int rL=min(a[idx].Y,seg[R[cL]].Y)-a[idx].X,rR=a[idx].Y-max(a[idx].X,seg[L[cR]].X);
            int sM=get(cL),rM=seg[sM].Y-seg[sM].X;
            ///optimize answer
//            printf("%d %d %d %d %d\n",coor[i],idx,R[cL],L[cR],sM);
//            printf("%lld %lld %lld\n",1LL*v[idx]*rL,1LL*v[idx]*rR,1LL*v[idx]*rM);
            if (maximize(ans,1LL*v[idx]*rL)) ansa=idx,anss=R[cL];
            if (maximize(ans,1LL*v[idx]*rR)) ansa=idx,anss=L[cR];
            if (maximize(ans,1LL*v[idx]*rM)) ansa=idx,anss=sM;
        }
    }
    printf("%lld\n",ans);
    if (ans) printf("%d %d",anss,ansa);
}
int main(){
    prepare();
    solve();
}