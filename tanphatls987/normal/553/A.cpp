#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=1e3+10,M=1e6+10;

ll rev[M],fac[M],refac[M];
int n,a[N];
void prepare(){
    rev[1]=1;
    REP(i,2,M) rev[i]=MOD-(MOD/i)*rev[MOD%i]%MOD;
    fac[0]=1;
    REP(i,1,M) fac[i]=fac[i-1]*i%MOD;
    refac[0]=1;
    REP(i,1,M)  refac[i]=refac[i-1]*rev[i]%MOD;
}
int C(int x,int y){
    return fac[x]*refac[y]%MOD*refac[x-y]%MOD;
}
int solve(){
    ll ans=1;
    int sum=0;
    FOR(i,1,n){
        sum+=a[i];
        ans=ans*C(sum-1,a[i]-1)%MOD;
    }
    return ans;
}
int main(){
    prepare();
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    cout<<solve();
}