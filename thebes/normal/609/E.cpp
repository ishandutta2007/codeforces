#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2e5+5, LG = 19;
struct edge{int x, y, w;}e[MN]; ll ans;
int N, M, i, x, y, w, dep[MN], sp[MN][LG], anc[MN][LG], ds[MN], ord[MN], u[MN];
vector<pii> adj[MN];

int fnd(int x){return ds[x]=x==ds[x]?x:fnd(ds[x]);}
void dfs(int n,int p,int d){
    anc[n][0] = p; dep[n] = d;
    for(auto v : adj[n]){
        if(v.first==p){
            sp[n][0] = v.second;
            continue;
        }
        dfs(v.first, n, d+1);
    }
}
int qu(int x,int y){
    int mx = 0;
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=dep[x]-dep[y]){
            mx = max(mx, sp[x][i]);
            x = anc[x][i];
        }
    }
    if(x==y) return mx;
    for(int i=LG-1;i>=0;i--){
        if(anc[x][i]!=anc[y][i]){
            mx = max(mx, max(sp[x][i],sp[y][i]));
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return max(mx, max(sp[x][0],sp[y][0]));
}

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=M;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w), ord[i]=i;
    for(i=1;i<=N;i++) ds[i]=i;
    sort(ord+1,ord+M+1,[](int i,int j){return e[i].w<e[j].w;});
    for(i=1;i<=M;i++){
        x = e[ord[i]].x, y = e[ord[i]].y;
        if(fnd(x)!=fnd(y)){
            ds[fnd(x)] = fnd(y);
            ans += e[ord[i]].w;
            adj[x].push_back({y,e[ord[i]].w});
            adj[y].push_back({x,e[ord[i]].w});
            u[ord[i]]=1;
        }
    }
    dfs(1,0,1);
    for(int j=1;j<LG;j++){
        for(i=1;i<=N;i++){
            sp[i][j]=max(sp[i][j-1],sp[anc[i][j-1]][j-1]);
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
    for(i=1;i<=M;i++){
        if(u[i]) printf("%lld\n",ans);
        else printf("%lld\n",ans-qu(e[i].x,e[i].y)+e[i].w);
    }
    return 0;
}