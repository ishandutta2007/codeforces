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
const int N=5e2+10;

int n,m,x,y,d[N][N],ans[N][N],v[N*N][2],w[N*N],in[N][N];
vector <int> e[N];
void solve(){
    FOR(k,1,n)
        FOR(i,1,n)
            FOR(j,1,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<d[i][j]<<" \n"[j==n];
    FOR(i,1,n)
        FOR(x,1,n)
            for(auto k:e[x]){
                int y=v[k][0]+v[k][1]-x;
                in[i][x]+=(d[i][y]+w[k]==d[i][x]);
            }
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<in[i][j]<<" \n"[j==n];
    FOR(i,1,n)
        FOR(j,i+1,n)
            FOR(k,1,n) if (d[i][k]+d[k][j]==d[i][j])
                ans[i][j]+=in[i][k];
    FOR(i,1,n)
        FOR(j,i+1,n) printf("%d ",ans[i][j]);
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n)
        FOR(j,1,n) d[i][j]=(i!=j)?inf:0;
    REP(i,0,m){
        scanf("%d%d%d",&x,&y,w+i);
        v[i][0]=x;v[i][1]=y;
        d[x][y]=d[y][x]=w[i];
        e[x].push_back(i);
        e[y].push_back(i);
    }
    solve();
}