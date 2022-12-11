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
const int N=2e2+10,M=1e6+10;
const int alp=10;


vector <ii> pos;
ii s[M];
int n,m,q,a[N][N],f[N][N],h[N][N],len[N][N],dx[10],dy[10],deg[N][N],g[M];
string str;
bool check(int x,int y){
    return x>0&&x<=n&&y>0&&y<=m;
}
void DFS(int sx,int sy){
    int top=1,spe=0;
    int v=0;
    s[1]=ii(sx,sy);
    while (!spe){
        int cx=s[top].X,cy=s[top].Y;
        h[cx][cy]=top;
        int nx=cx+dx[a[cx][cy]],ny=cy+dy[a[cx][cy]];

        if (!check(nx,ny)) spe=top;
        else {
            if (f[nx][ny]){
                spe=top+1;
                v=f[nx][ny];
                s[top+1]=ii(nx,ny);
                break;
            }
            if (!h[nx][ny]) s[++top]=ii(nx,ny);
            else spe=h[nx][ny];
        }
    }
    FOR(i,spe,top) v|=(1<<(a[s[i].X][s[i].Y]));
    FOR(i,1,top) f[s[i].X][s[i].Y]=v;
    FORD(i,spe-1,1) len[s[i].X][s[i].Y]=len[s[i+1].X][s[i+1].Y]+1;
}
void prepare(){
    cin>>n>>m>>q;
    FOR(i,1,n) {
        cin>>str;
        FOR(j,1,m) a[i][j]=str[j-1]-'0';
    }
    REP(i,0,alp) cin>>dx[i]>>dy[i];
    FOR(i,1,n)
        FOR(j,1,m){
            int nx=i+dx[a[i][j]],ny=j+dy[a[i][j]];
            if (check(nx,ny)) deg[nx][ny]++;
        }
    FOR(i,1,n)
        FOR(j,1,m) if (!deg[i][j]) {
            DFS(i,j);
            pos.push_back(ii(i,j));
        }
//    FOR(i,1,n)
//        FOR(j,1,m) cout<<f[i][j]<<" \n"[j==m];
    FOR(i,1,n)
        FOR(j,1,m) if (!f[i][j]) {
            DFS(i,j);
            pos.push_back(ii(i,j));
        }
//    FOR(i,1,n)
//        FOR(j,1,m) cout<<f[i][j]<<" \n"[j==m];
}
string solve(){
    int n1=str.length();
    g[n1]=0;
    FORD(i,n1-1,0) g[i]=g[i+1]|(1<<(str[i]-'0'));
    for(auto x:pos){
        int cur=0;
        ii cx=x;
        while (cur<n1&&len[cx.X][cx.Y]){
            int v=a[cx.X][cx.Y];
            if (str[cur]-'0'==v) cur++;
            int nx=cx.X+dx[v],ny=cx.Y+dy[v];
            cx=ii(nx,ny);
        }
        if ((g[cur]&f[cx.X][cx.Y])==g[cur]) return "YES";
    }
    return "NO";
}
int main(){
    prepare();
    while (q--){
        cin>>str;
        cout<<solve()<<'\n';
    }
}