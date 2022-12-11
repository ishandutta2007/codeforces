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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;
const string NAME="DIMA";
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

int h[N*N]={0},deg[N*N]={0},n,m,f[N*N];
queue <int> q;
char s[N][N];
vector <int> a[N*N];
bool check(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}
int cv(char x){
    return NAME.find(x);
}
int DFS(int x){
    if (h[x]==-1){
        printf("Poor Inna!");
        exit(0);
    }
    if (h[x]) return f[x];
    h[x]=-1;f[x]=1;
    for(auto i:a[x]) f[x]=max(f[x],DFS(i)+1);
    h[x]=1;
    return f[x];
}
void solve(){
    int ans=0;
    REP(i,0,n)
        REP(j,0,m) if (s[i][j]=='D') ans=max(ans,DFS(i*m+j)/4);
    if (ans==0) printf("Poor Dima!");
    else printf("%d",ans);
}
int main(){
    scanf("%d%d",&n,&m);
    REP(i,0,n) scanf("\n%s",s[i]);
    REP(i,0,n)
        REP(j,0,m)
            FOR(k,0,3){
            int ni=i+dx[k],nj=j+dy[k];
            if (!check(ni,nj)) continue;
            if ((cv(s[i][j])+1)%4==cv(s[ni][nj])) a[i*m+j].push_back(ni*m+nj),deg[ni*m+nj]++;
        }
    solve();
}