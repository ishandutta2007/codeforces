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
const int N=2e3+10;
const int dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,-1,0,1,-1,0,1};
int a[N][N],n,m,h[N][N];
string s;
bool ok(int x,int y){
    if (!a[x][y]) return false;
    if (x>n||x==0||y>m||y==0) return false;
    if (a[x-1][y-1]+a[x-1][y]+a[x][y-1]==0) return true;
    if (a[x-1][y+1]+a[x-1][y]+a[x][y+1]==0) return true;
    if (a[x+1][y-1]+a[x+1][y]+a[x][y-1]==0) return true;
    if (a[x+1][y+1]+a[x+1][y]+a[x][y+1]==0) return true;
    return false;
}
int main(){
    cin>>n>>m;
    FOR(i,1,n){
        cin>>s;
        FOR(j,1,m) a[i][j]=s[j-1]=='*';
    }
    FOR(i,1,n) a[i][0]=a[i][m+1]=1;
    FOR(i,1,m) a[0][i]=a[n+1][i]=1;
    queue <ii> q;
    FOR(i,1,n)
        FOR(j,1,m){
            //FOR(k,0,3) h[i][j]+=1-a[i+dx[k]][j+dy[k]];
            if (ok(i,j)) q.push(ii(i,j));
        }
    while (!q.empty()){
        int cx=q.front().X,cy=q.front().Y;
        q.pop();
        if (!a[cx][cy]) continue;
        a[cx][cy]=0;
        FOR(k,0,7){
            int nx=cx+dx[k],ny=cy+dy[k];
            if (ok(nx,ny)) q.push(ii(nx,ny));
        }
    }
    FOR(i,1,n){
        FOR(j,1,m) printf("%c",(a[i][j]?'*':'.'));
        ENDL;
    }
}