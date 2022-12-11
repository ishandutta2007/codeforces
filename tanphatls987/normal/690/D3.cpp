#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d3.inp","r",stdin)
#define OUTPUT freopen("d3.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e6+3;
const int N=1e2+5;

int n,wid,hei;
ll f[N],phei[N];
struct matrix{
    ll a[N][N];
    matrix(){
        memset(a,0,sizeof(a));
    }
}base,cur;
matrix operator *(matrix a,matrix b){
    matrix ans;
    FOR(i,0,wid)
        FOR(j,0,wid)
            FOR(k,0,wid) ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%MOD;
    return ans;
}
void prepare(){
    cin>>n>>wid>>hei;
    phei[0]=1;
    FOR(i,1,wid) phei[i]=phei[i-1]*hei%MOD;
    f[0]=1;
    FOR(i,1,wid)
        for(int j=1;j<=min(i,wid);j++) f[i]=(f[i]+f[i-j]*phei[j-1])%MOD;
    FOR(i,1,wid) base.a[i][i-1]=1;
    FOR(i,0,wid) base.a[i][wid]=phei[wid-i];
//    FOR(i,0,wid) cout<<f[i]<<" ";ENDL;
}
ll solve(){
    n++;
    if (n<=wid) return f[n];
    n-=wid;
    FOR(i,0,wid) cur.a[i][i]=1;
//    FOR(i,0,wid)
//        FOR(j,0,wid) cout<<base.a[i][j]<<" \n"[j==wid];
    while (n){
        if (n&1) cur=cur*base;
        base=base*base;
        n>>=1;
    }
//    FOR(i,0,wid)
//        FOR(j,0,wid) cout<<cur.a[i][j]<<" \n"[j==wid];
    ll ans=0;
    FOR(i,0,wid) ans=(ans+f[i]*cur.a[i][wid])%MOD;
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}