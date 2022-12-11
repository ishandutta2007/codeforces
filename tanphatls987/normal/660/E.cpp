#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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

int n,m;
ll f[N];
ll power(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}
ll solve(){
    ll sum=0,pb=1,cur=0;
    FOR(i,1,n){
        /*
        sum=(sum+(f[i-1]-cur+MOD)*m)%MOD;
        f[i]=(2LL*sum+pb)%MOD;
//        sum=(sum+(f[i]-cur+MOD)*m)%MOD;
        pb=(pb*m)%MOD;
        cur=(cur*(m-1)+f[i]*m)%MOD;*/
        f[i]=(f[i-1]*(2*m-1)+pb)%MOD;
        pb=pb*m%MOD;
//        cout<<i<<" "<<f[i]<<'\n';
//        cout<<i<<" "<<f[i]<<" "<<sum<<" "<<pb<<" "<<cur<<'\n';
    }
    return (m*f[n]+power(m,n))%MOD;
}
int main(){
//    freopen("input.inp","r",stdin);
    cin>>n>>m;
    cout<<solve();
}