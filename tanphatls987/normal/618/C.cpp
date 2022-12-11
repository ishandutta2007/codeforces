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

ii a[N];
int n,p[N];
ll sqr(ll x){return x*x;}
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
ll operator %(ii a,ii b){
    return 1LL*a.X*b.Y-1LL*a.Y*b.X;
}
ll sqrdist(ii a,ii b){
    return sqr(a.X-b.X)+sqr(a.Y-b.Y);
}
bool comp(int x,int y){
    return sqrdist(a[x],a[1])<sqrdist(a[y],a[1]);
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
}
void solve(){
    FOR(i,3,n) if ((a[p[i]]-a[1])%(a[p[2]]-a[1])!=0){
        printf("1 %d %d\n",p[2],p[i]);
        return;
    }
}
int main(){
    prepare();
    solve();
}