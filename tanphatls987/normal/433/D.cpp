#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
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
const int N=1e3+10;

int n,m,q,x,y,tmp,f[4][N][N],a[N][N];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n)
        FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(j,1,m)
        FOR(i,1,n) if (a[i][j]) f[0][i][j]=f[0][i-1][j]+1;
        else f[0][i][j]=0;
    FOR(j,1,m)
        FORD(i,n,1) if (a[i][j]) f[1][i][j]=f[1][i+1][j]+1;
        else f[1][i][j]=0;
    FOR(i,1,n)
        FOR(j,1,m) if (a[i][j]) f[2][i][j]=f[2][i][j-1]+1;
        else f[2][i][j]=0;
    FOR(i,1,n)
        FORD(j,m,1) if (a[i][j]) f[3][i][j]=f[3][i][j+1]+1;
        else f[3][i][j]=0;
    while (q--){
        scanf("%d%d%d",&tmp,&x,&y);
        if (tmp==1){
            a[x][y]^=1;
            FOR(i,x,n) if (a[i][y]) f[0][i][y]=f[0][i-1][y]+1;
            else f[0][i][y]=0;
            FORD(i,x,1) if (a[i][y]) f[1][i][y]=f[1][i+1][y]+1;
            else f[1][i][y]=0;
            FOR(j,y,m) if (a[x][j]) f[2][x][j]=f[2][x][j-1]+1;
            else f[2][x][j]=0;
            FORD(j,y,1) if (a[x][j]) f[3][x][j]=f[3][x][j+1]+1;
            else f[3][x][j]=0;
        }else{
            int h1=inf,h2=inf,ans=0;
            FORD(j,y,1){
                h1=min(h1,f[0][x][j]);
                h2=min(h2,f[1][x][j]);
                ans=max(ans,(h1+h2-1)*(y-j+1));
            }
            h1=h2=inf;
            FOR(j,y,m){
                h1=min(h1,f[0][x][j]);
                h2=min(h2,f[1][x][j]);
                ans=max(ans,(h1+h2-1)*(j-y+1));
            }
            h1=h2=inf;
            FORD(i,x,1){
                h1=min(h1,f[2][i][y]);
                h2=min(h2,f[3][i][y]);
                ans=max(ans,(h1+h2-1)*(x-i+1));
            }
            h1=h2=inf;
            FOR(i,x,n){
                h1=min(h1,f[2][i][y]);
                h2=min(h2,f[3][i][y]);
                ans=max(ans,(h1+h2-1)*(i-x+1));
            }
            printf("%d\n",ans);
        }
    }
}