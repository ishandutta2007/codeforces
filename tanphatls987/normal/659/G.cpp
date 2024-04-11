#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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

int n,a[N];
ll f[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) a[i]--;
}
ll solve(){
    ll ans=0;
    FOR(st,1,n){
        int peak=st;
        while (peak<n&&a[peak+1]>=a[peak]) peak++;
        int en=peak;
        while (en<n&&a[en+1]<=a[en]) en++;
        ///left hand side
        FOR(i,st,peak){
            f[i]=(f[i-1]*a[i-1]+a[i])%MOD;
            ans=(ans+f[i])%MOD;
        }
        ///right hand side
        if (en>peak){
            FORD(i,en,peak){
                f[i]=(f[i+1]*a[i+1]+a[i])%MOD;
                ans=(ans+f[i])%MOD;
            }
            ans=(ans-a[peak]+MOD)%MOD;
            ///combine
            ans=(ans+f[peak-1]*f[peak+1]%MOD*min(a[peak-1],a[peak+1]))%MOD;
            ///attach to right side
            ll force=a[en];
            f[en]=a[en];
            FORD(i,en-1,peak+1) {
                force=force*a[i+1]%MOD;
                f[en]=(f[en]+force)%MOD;
            }
            f[en]=(f[en]+force*a[peak+1])%MOD;
            force=force*min(a[peak-1],a[peak+1])%MOD;
            f[en]=(f[en]+force*f[peak-1])%MOD;
        }
//        cout<<st<<" "<<peak<<" "<<en<<" "<<f[en]<<'\n';
        st=en;
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}