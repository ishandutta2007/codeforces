#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;
const int dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};

int n,m,a[N][N],h[N][N],f[N*N];
queue <ii> q;
map <int,int> ma;
string s;
bool check(int x,int y){
    return a[x][y]&&!h[x][y];
}
void BFS(int sx,int sy){
    static int c=0;
    q.push(ii(sx,sy));
    h[sx][sy]=++c;
    while (!q.empty()){
        ii cur=q.front();q.pop();
        f[c]++;
        FOR(i,0,3){
            int nx=cur.X+dx[i],ny=cur.Y+dy[i];
            if (check(nx,ny)){
                h[nx][ny]=c;
                q.push(ii(nx,ny));
            }
        }
    }
}
void prepare(){
    cin>>n>>m;
    FOR(i,1,n){
        cin>>s;
        FOR(j,1,m) a[i][j]=s[j-1]=='.';
    }
    FOR(i,1,n)
        FOR(j,1,m) if (check(i,j)) BFS(i,j);
//    FOR(i,1,n)
//        FOR(j,1,m) cout<<h[i][j]<<" \n"[j==m];
    FOR(i,1,n){
        FOR(j,1,m) if (!a[i][j]){
            ma.clear();
            int ans=1;
            FOR(k,0,3){
                int cx=i+dx[k],cy=j+dy[k];
                if (!ma[h[cx][cy]]) ans+=f[h[cx][cy]];
                ma[h[cx][cy]]=1;
            }
            printf("%d",ans%10);
        }else printf(".");
        ENDL;
    }
}
void solve(){

}
int main(){
    prepare();
    solve();
}