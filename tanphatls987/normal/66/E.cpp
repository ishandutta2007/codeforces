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
const int N=2e5+10;

ll f[N];
int n,x,p[N],a[N],b[N],ans[N];
bool comp(int x,int y){
    if (f[x]==f[y]) return x<y;
    return f[x]<f[y];
}
void solve(){
    FOR(i,n+1,2*n) a[i]=a[i-n],b[i]=b[i-n];
    FOR(i,1,2*n) f[i]=f[i-1]+a[i]-b[i];
    REP(i,0,2*n) p[i]=i;
    sort(p,p+2*n,comp);
    int L=-1;
    REP(i,0,2*n){
        int x=p[i];
        if (x>L&&x<n) ans[x+1]=1;
        L=max(L,x);
    }
    b[0]=b[n];
    FOR(i,1,2*n) f[i]=f[i-1]+a[2*n-i+1]-b[2*n-i];
//    FOR(i,1,2*n) cout<<f[i]<<" \n"[i==2*n];
    L=-1;
    sort(p,p+2*n,comp);
//    REP(i,0,2*n) printf("%d ",p[i]);ENDL;
    REP(i,0,2*n){
        int x=p[i];
        if (x>L&&x<n) ans[n-x]=1;
        L=max(L,x);
    }
    ///
    printf("%d\n",count(ans+1,ans+n+1,1));
    FOR(i,1,n) if (ans[i]) printf("%d ",i);
}
int main(){
//    INPUT;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) scanf("%d",b+i);
    solve();

}