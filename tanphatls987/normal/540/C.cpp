#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("301.inp","r",stdin)
#define OUTPUT freopen("301.out","w",stdout)
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
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,m,h[N][N];
char s[N][N];
ii st,en;
bool check(int x,int y){
    return (x>0&&x<=n&&y>0&&y<=m);
}
queue <ii> q;
bool solve(){
    if (st.X==en.X&&st.Y==en.Y){
        int c=0;
        FOR(i,0,3){
            int nx=st.X+dx[i],ny=st.Y+dy[i];
            c+=(check(nx,ny)&&s[nx][ny-1]=='.');
        }
        return (c>=1);
    }
    int c=0;
    FOR(i,0,3){
        int nx=en.X+dx[i],ny=en.Y+dy[i];
        c+=(check(nx,ny)&&(s[nx][ny-1]=='.'||(nx==st.X&&ny==st.Y)));
    }
    if (c<=(s[en.X][en.Y-1]=='.')) return 0;
    q.push(st);
    while (!q.empty()){
        int x=q.front().X,y=q.front().Y;
        //printf("%d %d\n",x,y);
        q.pop();
        FOR(i,0,3){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx==en.X&&ny==en.Y) return 1;
            if (!check(nx,ny)||s[nx][ny-1]=='X'||h[nx][ny]) continue;
            h[nx][ny]=1;
            q.push(ii(nx,ny));
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("\n%s",s[i]);
    scanf("%d%d%d%d",&st.X,&st.Y,&en.X,&en.Y);
    cout<<(solve()?"YES":"NO");
}