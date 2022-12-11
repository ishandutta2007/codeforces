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
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

char s[N][N];
int n,m,h[N][N];
queue <ii> q;
bool check(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='T';
}
void prepare(){
    scanf("%d%d",&n,&m);
    REP(i,0,n) scanf("%s",s[i]);
}
int solve(){
    ii st,en;
    REP(i,0,n)
        REP(j,0,m){
            if (s[i][j]=='S') st=ii(i,j);
            if (s[i][j]=='E') en=ii(i,j);
        }
    q.push(en);
    h[en.X][en.Y]=1;
    while (!q.empty()){
        int x=q.front().X,y=q.front().Y;
        q.pop();
        FOR(i,0,3){
            int nx=x+dx[i],ny=y+dy[i];
            if (check(nx,ny)&&!h[nx][ny]){
                h[nx][ny]=h[x][y]+1;
                q.push(ii(nx,ny));
            }
        }
    }
    int ans=0;
    REP(i,0,n)
        REP(j,0,m) if (s[i][j]>='0'&&s[i][j]<='9'&&h[i][j]<=h[st.X][st.Y]&&h[i][j]) ans+=s[i][j]-'0';
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}