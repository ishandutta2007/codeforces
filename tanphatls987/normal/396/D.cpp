#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("232.inp","r",stdin)
#define OUTPUT freopen("232.out","w",stdout)
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
const int N=1e6+10;

int n,b[N],a[N];
ll fac[N],g[N];
void add(int x,int v){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    fac[0]=1;
    FOR(i,1,n) fac[i]=fac[i-1]*i%MOD;
    FOR(i,1,n) g[i]=(i*g[i-1]+1LL*i*(i-1)/2%MOD*fac[i-1])%MOD;
}
ll solve(){
    ll ans=0,sum=0;
    FOR(i,1,n){
        int pos=a[i]-get(a[i]);
        ans=(ans+(pos-1)*g[n-i]+sum*(pos-1)%MOD*fac[n-i]+1LL*(pos-2)*(pos-1)/2%MOD*fac[n-i])%MOD;
        sum=(sum+pos-1)%MOD;
        add(a[i],1);
    }
    return (ans+sum)%MOD;
}
int main(){
    prepare();
    cout<<solve();
}