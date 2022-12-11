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

const ll inf=1e15;
const int MOD=1e9+7;
const int N=3e2+10,M=1e5+10;

int n,m,k;
ll f[N][N],w[N][N];
ll solve(){
    FOR(i,1,k) f[0][i]=inf;
    FOR(i,1,n){
        ll cost=inf;
        FOR(j,1,k) f[i][j]=f[i-1][j];
        FOR(j,1,i) {
            cost=min(cost,w[j][i]);
            REP(j1,0,k-(i-j)) f[i][j1+(i-j+1)]=min(f[i][j1+(i-j+1)],f[j-1][j1]+cost);
        }
    }
    return (f[n][k]==inf)?-1:f[n][k];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n)
        FOR(j,i,n) w[i][j]=inf;
    FOR(i,1,m){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        w[x][y]=min(w[x][y],ll(v));
    }
    cout<<solve();
}