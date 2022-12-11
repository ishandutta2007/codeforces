#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=20,M=1e4+10,msiz=N*N;
const int dx[5]={1,-1,0,0,0},dy[5]={0,0,1,-1,0};

int base[msiz][msiz],n,m,k,f[msiz],a[M][4],cur[msiz][msiz],tmp[msiz][msiz],cb[msiz][msiz],siz,h[N][N];

bool check(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<m&&!h[x][y]);
}
void modified(int x,int y,int type){
    if (!type) f[x*m+y]=0;
    h[x][y]=type^1;
    FOR(i,0,4){
        int nx=x+dx[i],ny=y+dy[i];
        if (check(nx,ny)) base[x*m+y][nx*m+ny]=base[nx*m+ny][x*m+y]=type;
    }
}
void init(){
    REP(x,0,n)
        REP(y,0,m) modified(x,y,1);
    siz=n*m;
//    REP(i,0,siz)
//        REP(j,0,siz) cout<<base[i][j]<<" \n"[j==siz-1];
    f[0]=1;

}
void upmatrix(int x){
    memset(cur,0,sizeof(cur));
    REP(i,0,siz) cur[i][i]=1;
    REP(i,0,siz)
        REP(j,0,siz) cb[i][j]=base[i][j];
    while (x){
        ///
        if (x&1){
            REP(i,0,siz)
                REP(j,0,siz) tmp[i][j]=cur[i][j],cur[i][j]=0;
            REP(i,0,siz)
                REP(j,0,siz)
                    REP(k,0,siz) cur[i][j]=(cur[i][j]+1LL*tmp[i][k]*cb[k][j])%MOD;
        }
        ///
        REP(i,0,siz)
            REP(j,0,siz) tmp[i][j]=cb[i][j],cb[i][j]=0;
        REP(i,0,siz)
            REP(j,0,siz)
                REP(k,0,siz) cb[i][j]=(cb[i][j]+1LL*tmp[i][k]*tmp[k][j])%MOD;
        x>>=1;
    }
    REP(i,0,siz) tmp[0][i]=f[i];
    memset(f,0,sizeof(f));
    REP(i,0,siz)
        REP(j,0,siz) f[i]=(f[i]+1LL*tmp[0][j]*cur[j][i])%MOD;
}
void solve(){
    init();
    FOR(i,1,k){
//        FOR(j,0,3) printf("%d ",a[i][j]);ENDL;
        upmatrix(a[i][3]-a[i-1][3]);
        if (a[i][0]==0) printf("%d\n",f[a[i][1]*m+a[i][2]]);
        if (a[i][0]==1) modified(a[i][1],a[i][2],0);
        if (a[i][0]==2) modified(a[i][1],a[i][2],1);
//        printf("%d %d\n",i,a[i][3]);
//        REP(i,0,n)
//            REP(j,0,m) cout<<f[i*m+j]<<" \n"[j==m-1];
//        REP(i,0,siz)
//            REP(j,0,siz) cout<<base[i][j]<<" \n"[j==siz-1];
//            ENDL;

    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,k)
        FOR(j,0,3) scanf("%d",a[i]+j),a[i][j]--;
    solve();
}