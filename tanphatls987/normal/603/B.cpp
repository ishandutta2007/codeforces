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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int mod,k,h[N];
ll power(ll x,ll y,ll mod){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int solve(){
    ll ans=1;
    if (k==0) return power(mod,mod-1,MOD);
    REP(i,0,mod) if (!h[i]){
        int c=0,cur=i;
        while (!h[cur]){
            h[cur]=1;
            c++;
            cur=1LL*cur*k%mod;
        }
//        cout<<i<<" "<<c<<" "<<power'\n';
        if (power(k,c,mod)==1) ans=ans*mod%MOD;
    }
    return ans;
}
int main(){
    cin>>mod>>k;
    cout<<solve();
}