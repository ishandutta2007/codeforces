#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=60;

int d[N][N][N],f[N][N][N],n,m;

int main(){
    int test,x,y,z;
    scanf("%d%d%d",&n,&m,&test);
    REP(k,0,m){
        REP(i,0,n)
            REP(j,0,n) scanf("%d",&d[k][i][j]);
        REP(cur,0,n)
            REP(i,0,n)
                REP(j,0,n) d[k][i][j]=min(d[k][i][j],d[k][i][cur]+d[k][cur][j]);
    }
    REP(i,0,n)
        REP(j,0,n){
            f[0][i][j]=inf;
            REP(k,0,m) f[0][i][j]=min(f[0][i][j],d[k][i][j]);
        }
    REP(pha,1,n){
        REP(i,0,n)
            REP(j,0,n) f[pha][i][j]=f[pha-1][i][j];
        REP(i,0,n)
            REP(j,0,n)
                REP(k,0,n) f[pha][i][j]=min(f[pha][i][j],f[pha-1][i][k]+f[0][k][j]);
    }
    while (test--){
        scanf("%d%d%d",&x,&y,&z);
        printf("%d\n",f[min(z,n-1)][x-1][y-1]);
    }
}