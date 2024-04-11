#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e8;
const int MOD=1e9+7;
const int N=1e3+10;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int d[4][N][N],n,m,g[10][10];
string s[N];
queue <ii> q;
void prepare(){
    cin>>n>>m;
    REP(i,0,n) cin>>s[i];
}
bool check(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='#');
}
void BFS(int type){
    REP(i,0,n)
        REP(j,0,m) if (s[i][j]-'0'==type){
            d[type][i][j]=1;
            q.push(ii(i,j));
        }
    while (!q.empty()){
        ii cur=q.front();q.pop();
        FOR(i,0,3){
            int nx=cur.X+dx[i],ny=cur.Y+dy[i];
            if (!check(nx,ny)||d[type][nx][ny]) continue;
            d[type][nx][ny]=d[type][cur.X][cur.Y]+1;
            q.push(ii(nx,ny));
        }
    }
    REP(i,0,n)
        REP(j,0,m) if (!d[type][i][j]) d[type][i][j]=inf;
}
int solve(){
    FOR(i,1,3) BFS(i);
    int ans=inf;
    FOR(i,1,3)
        FOR(j,1,3) g[i][j]=inf;
    REP(i,0,n)
        REP(j,0,m) if (check(i,j)){
            FOR(i1,1,3)
                FOR(j1,1,3) g[i1][j1]=min(g[i1][j1],d[i1][i][j]+d[j1][i][j]-3);
            ans=min(ans,d[1][i][j]+d[2][i][j]+d[3][i][j]-5);
//            printf("%d %d\n",i,j);
//             FOR(i,1,3)
//                FOR(j,1,3) cout<<g[i][j]<<" \n"[j==3];
        }
//    FOR(i,1,3)
//        FOR(j,1,3) cout<<i<<" "<<j<<" "<<g[i][j]<<'\n';
    ans=min(ans,g[1][2]+g[2][3]);
    ans=min(ans,g[1][3]+g[1][2]);
    ans=min(ans,g[1][3]+g[2][3]);
    if (ans>n*m) return -1;
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}