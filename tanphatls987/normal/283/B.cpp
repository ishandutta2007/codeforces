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

const ll inf=1e15;
const int MOD=1e9+7;
const int N=2e5+10;

int n,h[2][N],a[N];
ll f[2][N];
ll DP(int pha,int x){
//    cout<<pha<<" "<<x<<'\n';
    if (x>n||x<=0) return 0;
    if (h[pha][x]==1) return inf;
    if (h[pha][x]==-1) return f[pha][x];
    h[pha][x]=1;
    if (pha==1) f[pha][x]=DP(0,x-a[x])+a[x];
    else f[pha][x]=DP(1,x+a[x])+a[x];
    h[pha][x]=-1;
//    cout<<pha<<" "<<x<<" "<<f[pha][x]<<'\n';
    return f[pha][x];
}
void prepare(){
    scanf("%d",&n);
    FOR(i,2,n) scanf("%d",a+i);
}
void solve(){
    h[0][1]=h[1][1]=1;
    REP(i,1,n) {
        ll v=DP(1,i+1);
        if (v<inf) printf("%lld\n",i+v);
        else printf("-1\n");
    }
}
int main(){
    prepare();
    solve();
}