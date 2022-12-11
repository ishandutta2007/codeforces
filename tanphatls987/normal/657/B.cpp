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
const int N=2e5+500;

int n,k;
ll a[N],co[N];
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,0,n) scanf("%lld",a+i);

}
int solve(){
    FOR(i,0,n+60) co[i]=a[i];
    FOR(i,0,n+60){
//        cout<<i<<" "<<co[i]<<'\n';
        if (co[i]<0){
            if (i>=n){
                FOR(j,0,n) a[j]*=-1;
                return solve();
            }
            ll v=-co[i];
            co[i]=v&1;
            co[i+1]-=(v>>1)+co[i];
            continue;
        }
        co[i+1]+=co[i]>>1;
        co[i]&=1;
    }
    int ans=0;
    int piv=0;
    while (!co[piv]) piv++;
    ll cur=0;
//    FOR(i,0,n+20) cout<<co[i]<<" ";ENDL;
    FORD(i,n+60,0){
        cur=min(cur*2+co[i],3LL*(k+1));
        if (i<=min(piv,n)&&abs(a[i]-cur)<=k) {
//            cout<<i<<" "<<cur<<
            if (i==n&&cur==a[n]) continue;
            ans++;
        }
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}