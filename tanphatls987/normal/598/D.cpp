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
const int N=1e3+10;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int n,m,k,f[N][N],h[N][N];
ii q[N*N];
char s[N][N];
void BFS(int sx,int sy){
    q[1]=ii(sx,sy);
    h[sx][sy]=1;
    int ans=0;
    int top=1,bot=1;
    while (top<=bot){
        ii cur=q[top++];
//        printf("%d %d\n",cur.X,cur.Y);
        FOR(i,0,3){
            int nx=cur.X+dx[i],ny=cur.Y+dy[i];
            if (s[nx][ny]=='*') ans++;
            else if (!h[nx][ny]){
                h[nx][ny]=1;
                q[++bot]=(ii(nx,ny));
            }
        }
    }
    FOR(i,1,bot) f[q[i].X][q[i].Y]=ans;
}
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    REP(i,0,n) scanf("\n%s",s[i]);
    REP(i,0,n)
        REP(j,0,m) if (s[i][j]=='.'&&!h[i][j])
            BFS(i,j);
}
int main(){
    prepare();
    while (k--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",f[x-1][y-1]);
    }
}