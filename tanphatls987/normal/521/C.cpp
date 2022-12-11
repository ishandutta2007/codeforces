#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

ll fac[N],re[N];
string s;
int n,m;
ll C(int x,int y){
    if (y>x||y<0||x<0) return 0;
    return ((fac[x]*re[x-y])%MOD*re[y])%MOD;
}
ll power(ll x,int y){
    if (y==0) return 1;
    if (y==1) return x%MOD;
    ll tmp=power(x,y/2);
    return ((tmp*tmp)%MOD*power(x,y%2))%MOD;
}

int main(){
    cin>>n>>m>>s;
    fac[0]=1;
    FOR(i,1,n) fac[i]=(fac[i-1]*i)%MOD;
    FOR(i,0,n) re[i]=power(fac[i],MOD-2);
    ll sum=0,ans=0,p10=1;
    for(auto c:s) sum+=c-'0';
    FOR(len,1,n){
        if (len>1) p10=(p10*10)%MOD;
        ans=(ans+(((s[n-len]-'0')*p10)%MOD)*C(n-len,m))%MOD;
        sum=(sum-(((s[n-len]-'0')*p10)%MOD)+MOD)%MOD;
        ans=(ans+sum*C(n-len-1,m-1))%MOD;
        sum=(sum*10)%MOD;
        //printf("%d %lld %lld %lld %d %d %lld\n",len,sum,p10,C(n-len,m),n-len,m,ans);
        //p10=(p10*10)%MOD;
    }
    cout<<ans;
}