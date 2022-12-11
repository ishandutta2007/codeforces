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
const int N=1e2+10;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

int n,m,ans[N][N];
void build(int x,int y){
    if (x>n) return;
    if (y>m){
        build(x+1,1);
        return;
    }
    if (ans[x][y]==-1){
        int use=0;
        FOR(to,1,4){
            FOR(k,0,3){
                int nx=x+dx[k],ny=y+dy[k];
                if (ans[nx][ny]==use){
                    use++;
                    break;
                }
            }
            if (use<to) break;
        }
        int edge=1;
        if (use<2){
            while (y+edge<=m&&x+edge<=n&&ans[x][y+edge]==-1){
                if (!use){
                    if (ans[x-1][y+edge]==0) break;
                    else edge++;
                }else{
                    if (ans[x-1][y+edge]) break;
                    else edge++;
                }
            }
        }
        REP(i,0,edge)
            REP(j,0,edge) ans[x+i][y+j]=use;
    }
    build(x,y+1);
}
int main(){
    scanf("%d%d",&n,&m);
    memset(ans,-1,sizeof(ans));
    build(1,1);
    FOR(i,1,n){
        FOR(j,1,m) printf("%c",'A'+ans[i][j]);
        ENDL;
    }
}