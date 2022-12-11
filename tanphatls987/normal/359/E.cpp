#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("359.inp","r",stdin)
#define OUTPUT freopen("359.out","w",stdout)
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
const char cdir[4]={'L','U','D','R'};
const int dx[4]={0,-1,1,0},dy[4]={-1,0,0,1};

int n,m,x0,y0,a[N][N],t[N][N],g[4][N][N],d[N][N][4];
queue <ii> q;
void prepare(){
    scanf("%d%d%d",&n,&x0,&y0);
    FOR(i,1,n)
        FOR(j,1,n) scanf("%d",a[i]+j);
    FOR(i,1,n){
        FOR(j,1,n) g[0][i][j]=g[0][i][j-1]||a[i][j-1];
        FORD(j,n,1) g[3][i][j]=g[3][i][j+1]||a[i][j+1];
    }
    FOR(j,1,n){
        FOR(i,1,n) g[1][i][j]=g[1][i-1][j]||a[i-1][j];
        FORD(i,n,1) g[2][i][j]=g[2][i+1][j]||a[i+1][j];
    }
    //
    t[x0][y0]=1;
    q.push(ii(x0,y0));
}
void DFS(int type,int x,int y){
    if (!type){
        if (!a[x][y]) printf("1");
        a[x][y]=1;
    }
    FOR(i,0,3) if (d[x][y][i]){
//        assert(g[i][x][y]);
        int nx=x+dx[i],ny=y+dy[i];
        printf("%c",cdir[i]);
        DFS(type,nx,ny);
        printf("%c",cdir[3-i]);
    }
    assert(a[x][y]);
    if (type){
        printf("2");
        a[x][y]=0;
    }
}
bool check(int nx,int ny,int cx,int cy,int type){
    if (max(nx,ny)>n||min(nx,ny)<1||t[nx][ny]||!g[type][cx][cy]) return 0;
    return 1;
}
void solve(){
    while (!q.empty()){
        ii cur=q.front();q.pop();
        FOR(i,0,3){
            int nx=cur.X+dx[i],ny=cur.Y+dy[i];
            if (!check(nx,ny,cur.X,cur.Y,i)) continue;
            t[nx][ny]=1;
            d[cur.X][cur.Y][i]=1;
            q.push(ii(nx,ny));
        }
    }
    FOR(i,1,n)
        FOR(j,1,n) if (a[i][j]&&!t[i][j]){
            printf("NO");
            return;
        }
    printf("YES\n");
    FOR(i,0,1) DFS(i,x0,y0);
}
int main(){
    prepare();
    solve();
}