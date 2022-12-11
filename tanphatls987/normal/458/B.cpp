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
const int N=1e5+10;

int n[2],a[2][N];
void prepare(){
    scanf("%d%d",n,n+1);
    FOR(i,1,n[0]) scanf("%d",a[0]+i);
    FOR(i,1,n[1]) scanf("%d",a[1]+i);
}
ll solve(){
    FOR(j,0,1) sort(a[j]+1,a[j]+n[j]+1);
    int sel=a[0][n[0]]<a[1][n[1]];
    ll sum=0;
    FOR(i,1,n[sel^1]) sum+=a[sel^1][i];
//    cout<<sel<<" "<<sum<<'\n';
    ll ans=sum;
    REP(i,1,n[sel]) ans+=min(ll(a[sel][i]),sum);
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}