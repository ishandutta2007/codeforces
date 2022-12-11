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
const int N=2e5+10;

int n,m,k,x,y,nscc,ncc=0,scc[N],cc[N],root[N],f[2][N]={0},v[N][2],low[N],num[N],p[N][20],lv[N]={0};
vector <int> e[N],v2[N];
stack <int> s;
void DFS(int idx,int x){
    static int t1=0;
    num[x]=low[x]=++t1;
    s.push(x);
    for(auto i:e[x]) if (i!=idx){
        int y=v[i][0]+v[i][1]-x;
        if (num[y]) low[x]=min(low[x],num[y]);
        else {
            DFS(i,y);
            low[x]=min(low[x],low[y]);
        }
    }
    if (low[x]>=num[x]){
        scc[x]=++nscc;
        while (s.top()!=x){
            scc[s.top()]=nscc;
            s.pop();
        }
        s.pop();
    }
}
void DFS2(int par,int x){
    lv[x]=lv[par]+1;
    p[x][0]=par;
    cc[x]=ncc;
    for(auto y:v2[x]) if (y!=par) DFS2(x,y);
}
void DFS3(int x){
    for(auto y:v2[x]) if (y!=p[x][0]){
        DFS3(y);
        FOR(j,0,1) f[j][x]+=f[j][y];
    }
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    for(int i=0,slv=lv[x]-lv[y];slv>0;i++,slv>>=1) if (slv&1) x=p[x][i];
    if (x==y) return x;
    FORD(i,18,0) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
void solve(){
    FOR(x,1,n)
        for(auto i:e[x]){
            int y=v[i][0]+v[i][1]-x;
            if (scc[x]!=scc[y]){
                int nx=scc[x],ny=scc[y];
                v2[nx].push_back(ny);
                v2[ny].push_back(nx);
//                printf("%d %d %d %d\n",x,y,nx,ny);
            }
        }
    FOR(x,1,nscc){
        sort(v2[x].begin(),v2[x].end());
        v2[x].resize(unique(v2[x].begin(),v2[x].end())-v2[x].begin());
    }
    FOR(i,1,nscc) if (!cc[i]){
        root[++ncc]=i;
        DFS2(0,i);
    }
    FOR(j,1,18)
        FOR(i,1,nscc) p[i][j]=p[p[i][j-1]][j-1];
//    FOR(i,1,n) printf("%d ",scc[i]);ENDL;
//    FOR(i,1,nscc) printf("%d ",cc[i]);ENDL;
//    ENDL;
    while (k--){
        scanf("%d%d",&x,&y);
        x=scc[x];y=scc[y];
        if (cc[x]!=cc[y]){
            printf("No");
            return;
        }
        int z=LCA(x,y);
//        printf("%d %d %d\n",x,y,z);
        f[0][x]++;f[0][z]--;
        f[1][y]++;f[1][z]--;
    }
    FOR(i,1,ncc) DFS3(root[i]);
//    printf("%d\n",root[1]);
//    FOR(i,1,nscc) printf("%d ",f[0][i]);ENDL;
//    FOR(i,1,nscc) printf("%d ",f[1][i]);ENDL;
    FOR(i,1,nscc) if (f[0][i]&&f[1][i]){
        printf("No");
        return;
    }
    printf("Yes");
}
int main(){
//    INPUT;
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m) {
        scanf("%d%d",&x,&y);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    FOR(i,1,n) if (!num[i]) DFS(0,i);
    solve();
}