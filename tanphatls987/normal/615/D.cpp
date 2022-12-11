#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=2e5+10;

int n,a[N],h[N];
ll g[2][N];
ll power(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
}
ll solve(){
    ll ans=1;
    int n1=0;
    for(int en=1;en<=n;){
        a[++n1]=a[en];
        while (en<=n&&a[en]==a[n1]) h[n1]++,en++;
    }
    g[0][0]=g[1][n1+1]=1;
    FOR(i,1,n1) g[0][i]=g[0][i-1]*(h[i]+1)%(MOD-1);
    FORD(i,n1,1) g[1][i]=g[1][i+1]*(h[i]+1)%(MOD-1);
    FOR(i,1,n1){
        ll v=(1LL*h[i]*(h[i]+1)/2)%(MOD-1)*g[0][i-1]%(MOD-1)*(g[1][i+1])%(MOD-1);
        ans=ans*power(a[i],v)%MOD;
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}