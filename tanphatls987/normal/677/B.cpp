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
const int N=1e5+10;

int n,hei,k,a[N];
void prepare(){
    scanf("%d%d%d",&n,&hei,&k);
    FOR(i,1,n) scanf("%d",a+i);
}
ll solve(){
    int chei=0;
    ll ans=0;
    FOR(i,1,n){
        if (chei+a[i]<=hei){
            chei+=a[i];
            continue;
        }
        chei=max(chei-k,0);
        ans++;
//        cout<<i<<" "<<chei<<" "<<ans<<'\n';
        int L=hei-a[i];
        int take=(max(chei-L,0)+k-1)/k;
        ans+=take;
        chei=max(0,chei-k*take);
        i--;
    }
    ans+=(chei+k-1)/k;
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}