#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=3e2+10;

int n,m,k;
int b[N][N],f[N][N],g[N];
vector <ii> p[N*N];
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n)
        FOR(j,1,m) scanf("%d",b[i]+j);
    FOR(i,1,n)
        FOR(j,1,m) p[b[i][j]].push_back(ii(i,j));
}
int solve(){
    for(auto i:p[1]) f[i.X][i.Y]=i.X+i.Y-2;
    FOR(lay,2,k){
        for(auto i:p[lay]) f[i.X][i.Y]=inf;
        int n1=p[lay-1].size(),n2=p[lay].size();
        fill(g+1,g+m+1,inf);
        for(int i=1,j1=0,j2=0;i<=n;i++){
            while (j1<n1&&p[lay-1][j1].X==i){
                ii cur=p[lay-1][j1++];
                int val=f[cur.X][cur.Y];
                FOR(j,1,m) g[j]=min(g[j],val-i+abs(j-cur.Y));
            }
            while (j2<n2&&p[lay][j2].X==i){
                ii cur=p[lay][j2++];
                f[cur.X][cur.Y]=min(f[cur.X][cur.Y],g[cur.Y]+i);
            }
        }
        fill(g+1,g+m+1,inf);
        for(int i=n,j1=n1-1,j2=n2-1;i>0;i--){
            while (j1>=0&&p[lay-1][j1].X==i){
                ii cur=p[lay-1][j1--];
                int val=f[cur.X][cur.Y];
                FOR(j,1,m) g[j]=min(g[j],val+i+abs(j-cur.Y));
            }
            while (j2>=0&&p[lay][j2].X==i){
                ii cur=p[lay][j2--];
                f[cur.X][cur.Y]=min(f[cur.X][cur.Y],g[cur.Y]-i);
            }
        }
    }
//    FOR(i,1,n)
//        FOR(j,1,m) cout<<f[i][j]<<" \n"[j==m];
    return f[p[k][0].X][p[k][0].Y];
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}