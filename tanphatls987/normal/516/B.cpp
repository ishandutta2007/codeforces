#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1
#define OUT printf("Not unique")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e3+10;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

int n,m,a[N][N],h[N][N]={0},deg[N][N]={0},c=0;
char s[N][N];
queue <ii> q;
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) {
        scanf("\n%s",s[i]);
        FOR(j,1,m) a[i][j]=(s[i][j-1]=='.');
    }
    FOR(i,1,n)
        FOR(j,1,m) if (a[i][j]){
            c++;
            if (a[i][j+1]) deg[i][j]++,deg[i][j+1]++;
            if (a[i+1][j]) deg[i][j]++,deg[i+1][j]++;
            if (deg[i][j]==1) q.push(ii(i,j));
        }
}
void solve(){
    if (c%2) {OUT;return;}
    while (!q.empty()){
        int x=q.front().X,y=q.front().Y;
        q.pop();
        if (h[x][y]||deg[x][y]!=1) continue;
        c-=2;
        FOR(i,0,3){
            int nx=x+dx[i],ny=y+dy[i];
            if (h[nx][ny]||!a[nx][ny]) continue;
            if (ny==y+1) s[x][y-1]='<',s[nx][ny-1]='>';
            else if (y==ny+1) s[x][y-1]='>',s[nx][ny-1]='<';
            else if (nx==x+1) s[x][y-1]='^',s[nx][ny-1]='v';
            else s[x][y-1]='v',s[nx][ny-1]='^';
            FOR(j,0,3){
                int nx1=nx+dx[j],ny1=ny+dy[j];
                if (h[nx1][ny1]||!a[nx1][ny1]) continue;
                deg[nx1][ny1]--;
                if (deg[nx1][ny1]==1) q.push(ii(nx1,ny1));
            }
            h[nx][ny]=1;
        }
        h[x][y]=1;
    }
    if (c) {OUT;return;}
    FOR(i,1,n) printf("%s\n",s[i]);
}
int main(){
    prepare();
    solve();
}