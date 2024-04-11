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
const int N=5e2+10;

int n,a[N],f[N][N],g[N][N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) f[i][i]=g[i][i]=1;
    FOR(i,2,n)
        FORD(j,i-1,1){
            f[j][i]=g[j][i]=g[j+1][i];
            REP(k,j,i) if (a[j]<a[k+1]) g[j][i]=(g[j][i]+1LL*f[j][k]*g[k+1][i])%MOD;
        }
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<f[i][j]<<" \n"[j==n];
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<g[i][j]<<" \n"[j==n];
    cout<<f[1][n];
}