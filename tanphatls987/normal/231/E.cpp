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
const int N=1e5+10;

int n,m,x,y,k,m1,m2,v[N][2],h[N],p[N][20],lv[N],g[N],f[N];
vector <int> e[N];
queue <int> q;
int power(int x,int y){
    int ans=1;
    while (y){
        if (y&1) ans=(1LL*ans*x)%MOD;
        x=1LL*x*x%MOD;
        y>>=1;
    }
    return ans;
}
void BFS(){
    q.push(1);
    lv[1]=1;
    f[1]=(1<=m2);
    while (!q.empty()){
        int x=q.front();q.pop();
//    printf("%d %d %d\n",x,p[x][0],f[x]);
        for(auto i:e[x]){
            int y=v[i][0]+v[i][1]-x;
            if (!lv[y]){
                h[i]=1;
                p[y][0]=x;lv[y]=lv[x]+1;
                f[y]=f[x]+(y<=m2);
                q.push(y);
            }
        }
    }
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    int tmp=lv[x]-lv[y];
    for(int i=0;(1<<i)<=tmp;i++) if (tmp&(1<<i))
        x=p[x][i];
    if (x==y) return x;
    for(int i=int(log2(lv[x]));i>=0;i--) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
int getpar(int x,int v){
    for(int i=0;(1<<i)<=v;i++) if (v&(1<<i)) x=p[x][i];
    return x;
}
void solve(){
    BFS();
    for(int i=1;i<=int(log2(n));i++)
        FOR(j,1,n) p[j][i]=p[p[j][i-1]][i-1];
    m1=0;
//    REP(i,0,m) printf("%d ",h[i]);ENDL;
    REP(i,0,m) if (!h[i]){
        int z=LCA(v[i][0],v[i][1]);
        ++m1;
        FOR(j,0,1){
            int x=v[i][j];
            while (x!=z){
                g[x]=m1;
                x=p[x][0];
            }
        }
        g[z]=m1;
    }
    m2=m1;
    FOR(i,1,n) if (!g[i]) g[i]=++m1;
    FOR(i,1,n) e[i].clear();
    REP(i,0,m){
        int x=g[v[i][0]],y=g[v[i][1]];
        v[i][0]=x,v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
        //printf("%d %d %d\n",i,x,y);
    }
    memset(lv,0,sizeof(lv));
    BFS();
    for(int i=1;i<=int(log2(m1));i++)
        FOR(j,1,m1) p[j][i]=p[p[j][i-1]][i-1];
//    FOR(i,1,n) printf("%d ",g[i]);ENDL;
//
//    for(int i=0;i<=int(log2(m1));i++){
//        FOR(j,1,m1) printf("%d ",p[j][i]);ENDL;
//    }
//    FOR(i,1,m1) printf("%d ",f[i]);ENDL;
}
int query(int x,int y){
    int nx=g[x],ny=g[y],nz=LCA(nx,ny);
//    printf("%d %d %d\n",nx,ny,nz);
    return power(2,f[nx]+f[ny]-f[nz]-f[p[nz][0]]);
}
int main(){
//    INPUT;
    scanf("%d%d",&n,&m);
    REP(i,0,m){
        scanf("%d%d",&x,&y);
        v[i][0]=x,v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    solve();
    scanf("%d",&k);
    while (k--){
        scanf("%d%d",&x,&y);
        printf("%d\n",query(x,y));
    }
}