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
const int N=60;

int n,a[N][N],ans[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j];
    FOR(i,1,n) a[i][i]=inf;
}
void solve(){
    FOR(pha,1,n)
        FOR(i,1,n) if (!ans[i]&&count(a[i]+1,a[i]+n+1,pha)==n-pha) {
            ans[i]=pha;
            break;
        }
    FOR(i,1,n) printf("%d ",ans[i]);
}
int main(){
    prepare();
    solve();
}