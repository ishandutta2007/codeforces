#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 1e5+5, LG = 20;
int sp[MN][LG], dep[MN], sz[MN], N, M, i, x, y, w;
vi adj[MN]; ll d[MN], u[MN];

void dfs(int n,int p,int dd){
    dep[n]=dd; sp[n][0]=p; sz[n] = 1;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs(v, n, dd+1); sz[n] += sz[v];
        d[n] += d[v]+sz[v];
    }
}

void dfs2(int n,int p,ll w){
    u[n] = w;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs2(v,n,w+d[n]-d[v]+N-2*sz[v]);
    }
}

int lca(int x,int y){
    w=0;
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=dep[x]-dep[y])
            x = sp[x][i], w += (1<<i);
    }
    if(x==y) return x;
    for(int i=LG-1;i>=0;i--){
        if(sp[x][i]!=sp[y][i]){
            x = sp[x][i];
            y = sp[y][i];
            w += (1<<(i+1));
        }
    }
    w += 2;
    return sp[x][0];
}

int adv(int x,int s){
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=s){
            s -= (1<<i);
            x = sp[x][i];
        }
    }
    return x;
}

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,1); dfs2(1,0,0);
    for(int j=1;j<LG;j++){
        for(i=1;i<=N;i++)
            sp[i][j]=sp[sp[i][j-1]][j-1];
    }
    for(i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        int l = lca(x,y);
        if(l==x||l==y){
            if(dep[x]>dep[y]) swap(x,y);
            int heh = adv(y,dep[y]-dep[x]-1);
            long double a = (u[heh]-(N-sz[heh]))/(long double)(N-sz[heh]);
            long double b = d[y]/(long double)sz[y];
            cout << fixed << setprecision(9) << a+b+w+1 << "\n";
        }
        else{
            long double a = d[x]/(long double)sz[x];
            long double b = d[y]/(long double)sz[y];
            cout << fixed << setprecision(9) << a+b+w+1 << "\n";
        }
    }
    return 0;
}