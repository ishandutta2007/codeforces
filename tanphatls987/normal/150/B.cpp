#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("107.inp","r",stdin)
#define OUTPUT freopen("107.out","w",stdout)
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
const int N=0;

int n,m,k;
ll power(ll x,int y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}
int solve(){
    if (k>n) return power(m,n);
    if (k==n) return power(m,(n+1)/2);
    if (k%2==0) return m;
    if (k==1) return power(m,n);
    return 1LL*m*m%MOD;
}
int main(){
    cin>>n>>m>>k;
    cout<<solve();
}