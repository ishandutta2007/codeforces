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
const int N=33,M=55;

int f[N][N][M];
template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void prepare(){
    REP(i,1,N)
        REP(j,1,N){
            fill(f[i][j]+1,f[i][j]+M,inf);
            FOR(k,1,min(i*j,M-1)){
                if (i*j==k) f[i][j][k]=0;
                REP(i1,1,i)
                    FOR(k1,0,k)
                        minimize(f[i][j][k],f[i1][j][k1]+f[i-i1][j][k-k1]+j*j);
                REP(j1,1,j)
                    FOR(k1,0,k)
                        minimize(f[i][j][k],f[i][j1][k1]+f[i][j-j1][k-k1]+i*i);
                //printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
            }
        }
}
int main(){
    prepare();
    int test;
    scanf("%d",&test);
    while (test--){
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n",f[x][y][k]);
    }
}