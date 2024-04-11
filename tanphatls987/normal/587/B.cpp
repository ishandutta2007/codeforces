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
const int N=1e6+10;

int n,n1,k,a[N],p[N],h[N],c[N],f[2][N];
ll m;
ll solve(){
    int en=m%n;
    ll rem=m/n;
    ///last part
    FOR(i,1,en) c[a[i]]++;
    FORD(i,n1,0) c[i]+=c[i+1];
    ///1 segment
    FOR(i,1,n) h[a[i]]++;
    ///
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
//    cout<<n1<<'\n';
//    FOR(i,1,n1) cout<<h[i]<<" \n"[i==n1];
    ll ans=en;
    int cur=0,last=1;
    f[0][0]=1;
//    cout<<ans<<'\n';
    FOR(i,1,k){
        FOR(j,1,n1) ans=(ans+1LL*f[cur][j]*c[j])%MOD;
        if (i>rem) break;
        swap(cur,last);
        FOR(j,1,n1) f[last][j]=(f[last][j]+f[last][j-1])%MOD;
        f[cur][0]=0;
        FOR(j,1,n1) f[cur][j]=1LL*f[last][j]*h[j]%MOD;
        FOR(j,1,n1) ans=(ans+(rem-i+1)%MOD*f[cur][j])%MOD;
    }

    return ans;
}

void prepare(){
    scanf("%d%I64d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d",a+i),p[i]=a[i];
    sort(p+1,p+n+1);
    n1=unique(p+1,p+n+1)-p-1;
    FOR(i,1,n) a[i]=lower_bound(p+1,p+n1+1,a[i])-p;
}
int main(){
    prepare();
    cout<<solve();
}