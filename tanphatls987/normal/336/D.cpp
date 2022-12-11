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

ll fac[N],refac[N],rev[N];
void prepare(){
    fac[0]=1;
    REP(i,1,N) fac[i]=fac[i-1]*i%MOD;
    rev[1]=1;
    REP(i,2,N) rev[i]=MOD-(MOD/i)*rev[MOD%i]%MOD;
    refac[0]=1;
    REP(i,1,N) refac[i]=refac[i-1]*rev[i]%MOD;
}
int C(int x,int y){
    if (y>x) return 0;
    return fac[x]*refac[y]%MOD*refac[x-y]%MOD;
}
int solve(int n,int m,int k){
    if (k==0) return (C(n+m,n)-solve(n,m,1)+MOD)%MOD;
    ll ans=0;
    if (!m) return (n%2==0);
    if (m==1) ans+=(n%2==0);
    for(int i=1;i<=n;i+=2) if (n-i+m>1) ans=(ans+C(m-1+n-i,m-1))%MOD;
    return ans;
}
int main(){
    prepare();
    int n,m,k;
    cin>>n>>m>>k;
    cout<<solve(n,m,k);
}