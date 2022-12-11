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
const int N=5e5+10;

int n,a[N];
ll g[2][N][2];
string s;
void prepare(){
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>s;
}
ll solve(){
    FOR(i,1,n)
        FOR(j,0,1) g[0][i][j]=g[0][i-1][j]+(s[i-1]-'A'==j?a[i]:0);
    FORD(i,n,1)
        FOR(j,0,1) g[1][i][j]=g[1][i+1][j]+(s[i-1]-'A'==j?a[i]:0);
    ll ans=0;
    FOR(i,0,n) ans=max(ans,max(g[0][i][0],g[0][i][1])+max(g[1][i+1][0],g[1][i+1][1]));
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}