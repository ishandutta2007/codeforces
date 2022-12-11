#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=1e5+10,M=20;


int n,pa[N][M],sub[N],lv[N];
int q[N];
ll f[2][N];
vector <int> v[N];
void BFS(){
    int top=1,bot=1;
    q[1]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (pa[x][0]!=y){
            pa[y][0]=x;
            lv[y]=lv[x]+1;
            q[++bot]=y;
        }
    }
}
int par(int x,int v){
    for(int i=0;v;i++,v>>=1) if (v&1) x=pa[x][i];
    return x;
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    x=par(x,lv[x]-lv[y]);
    if (x==y) return x;
    FORD(i,int(log2(lv[x])),0) if (pa[x][i]!=pa[y][i])
        x=pa[x][i],y=pa[y][i];
    return pa[x][0];
}
double query(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    int z=LCA(x,y);
    if (z==y) {
        int xa=par(x,lv[x]-lv[y]-1);
        return (f[0][x]+.0)/sub[x]+(f[1][y]-f[0][xa]-sub[xa]+.0)/(n-sub[xa])+lv[x]-lv[y]+1;
    }
    return lv[x]+lv[y]-2*lv[z]+(f[0][x]+.0)/sub[x]+(f[0][y]+.0)/sub[y]+1;
}
void prepare(){
    int m,x,y;
    scanf("%d%d",&n,&m);
    REP(i,1,n){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
    REP(lay,1,M)
        FOR(i,1,n) pa[i][lay]=pa[pa[i][lay-1]][lay-1];
    fill(sub+1,sub+n+1,1);
    FORD(pha,n,1){
        int x=q[pha];
        for(auto y:v[x]) if (pa[x][0]!=y){
            f[0][x]+=f[0][y]+sub[y];
            sub[x]+=sub[y];
        }
    }
    f[1][1]=f[0][1];
    FOR(pha,1,n){
        int x=q[pha];
        for(auto y:v[x]) if (pa[x][0]!=y)
            f[1][y]=f[0][y]+f[1][x]-(f[0][y]+sub[y])+(n-sub[y]);
    }
//    FOR(i,1,n) cout<<f[0][i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<f[1][i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<sub[i]<<" \n"[i==n];
    while (m--){
        scanf("%d%d",&x,&y);
        printf("%.12f\n",query(x,y));
    }
}
int main(){
    prepare();
}