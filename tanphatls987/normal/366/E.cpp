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
const int N=2e3+10;
const int dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1};

int n,m,k,m1,a[N][N],q[100005],g[10][4],f[10][10];
int main(){
    //OUTPUT;
    scanf("%d%d%d%d",&n,&m,&k,&m1);
    FOR(i,1,n)
        FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,m1) scanf("%d",q+i);
    FOR(i,1,k)
        FOR(j1,0,3) g[i][j1]=-inf;
    FOR(i,1,n)
        FOR(j,1,m)
            FOR(j1,0,3) {
                g[a[i][j]][j1]=max(g[a[i][j]][j1],dx[j1]*i+dy[j1]*j);
                //printf("%d %d %d %d\n",i,j,j1,dx[j1]*i+dy[j1]*j);
            }
//    FOR(i,1,k)
//        FOR(j,0,3) cout<<g[i][j]<<" \n"[j==3];
    FOR(j,1,k)
        FOR(i,1,k)
            FOR(j1,0,3) f[j][i]=max(f[j][i],g[j][j1]+g[i][j1^3]);
    int ans=0;
    FOR(i,1,m1-1) ans=max(ans,f[q[i]][q[i+1]]);
    cout<<ans;
}