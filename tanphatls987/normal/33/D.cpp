#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("33d.inp","r",stdin)
#define OUTPUT freopen("33d.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;

ii a[N];
iii b[N];
vector <int> e[N];
int n,m,k,x,y,g[N],lv[N],p[N][12]={0};
ll sqr(int x){return 1LL*x*x;}
ll distsqr(ii a,ii b){
    return sqr(a.X-b.X)+sqr(a.Y-b.Y);
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    int D=lv[x]-lv[y];
    for(int i=0;(1<<i)<=D;i++) if (D&(1<<i)) x=p[x][i];
    if (x==y) return x;
    FORD(i,int(log2(lv[x])),0) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    FOR(i,1,m) scanf("%d%d%d",&b[i].X,&b[i].Y.X,&b[i].Y.Y);
    sort(b+1,b+m+1);
    FORD(i,m,1){
        p[i][0]=m+1;
        FORD(j,m,i+1) if (distsqr(b[i].Y,b[j].Y)<sqr(b[j].X)) p[i][0]=j;
    }
    FOR(i,1,int(log2(m+1)))
        FOR(j,1,m) p[j][i]=p[p[j][i-1]][i-1];
    FOR(i,1,m) e[p[i][0]].push_back(i);
    queue <int> q;
    q.push(m+1);
    while (!q.empty()){
        int x=q.front();q.pop();
        lv[x]=lv[p[x][0]]+1;
        for(auto y:e[x]) q.push(y);
    }
    FOR(i,1,n){
        g[i]=m+1;
        FORD(j,m,1) if (distsqr(a[i],b[j].Y)<sqr(b[j].X)) g[i]=j;
        //cout<<g[i]<<" \n"[i==n];
    }
    //FOR(i,1,m+1) cout<<p[i][0]<<" \n"[i==m+1];
    while (k--){
        scanf("%d%d",&x,&y);
        printf("%d\n",lv[g[x]]+lv[g[y]]-2*lv[LCA(g[x],g[y])]);
    }
}