#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("340.inp","r",stdin)
#define OUTPUT freopen("340.out","w",stdout)
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

int a[2][3];
int solve(){
    FOR(j,0,1) if (count(a[j],a[j]+3,a[j][0])==3) return 1;
    FOR(type,0,1)
        FOR(i,0,2)
            FOR(j,i+1,2) if (a[type][i]==a[type][j]){
                int oth=a[type^1][3-i-j],L=min(a[type^1][i],a[type^1][j]),R=max(a[type^1][i],a[type^1][j]);
                if (oth>=R||oth<=L) return 2;
            }
    return 3;
}
int main(){
    FOR(i,0,2)
        FOR(j,0,1) cin>>a[j][i];
    cout<<solve();
}