#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("403d.inp","r",stdin)
#define OUTPUT freopen("403d.out","w",stdout)
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
const int N=1e3,M=N+3;

ll fac[M];
int f[2][M][M],g[M][M],test,x,y;
int main(){
    fac[0]=1;
    FOR(i,1,N) fac[i]=(fac[i-1]*i)%MOD;
    FOR(k,1,50){
        int last=(k+1)%2;
        if (k==1){
            FOR(j,1,N)
                REP(i,0,j) f[1][j][i]=1;
        }else {
            memset(f[k%2],0,sizeof(f[k%2]));
            FOR(j,1,N)
                REP(i,k-1,j) f[k%2][j][i]=f[last][j-(i+1)][i-1];
        }
//        FOR(j,0,N)
//            FOR(i,0,N) printf("%d %d %d\n",j,i,f[k%2][j][i]);
        FOR(j,1,N)
            FOR(i,0,N) {
                if (i) f[k%2][j][i]=(1LL*f[k%2][j][i]+f[k%2][j-1][i]+f[k%2][j][i-1]-f[k%2][j-1][i-1]+MOD)%MOD;
                else f[k%2][j][0]=(f[k%2][j][0]+f[k%2][j-1][0])%MOD;

            }
//        FOR(j,0,N)
//            FOR(i,0,N) printf("%d %d %d\n",j,i,f[k%2][j][i]);
        FOR(i,1,N) g[i][k]=(f[k%2][i][N]*fac[k])%MOD;
    }
    scanf("%d",&test);
    while (test--){
        scanf("%d%d",&x,&y);
        printf("%d\n",g[x][y]);
    }
}