#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 1e5+5, MK = 305, LG = 19, mod = 1e9+7;
int n, q, m, k, r, i, j, x, y, sp[MN][LG], dp[MK], tmp[MK], dep[MN], vis[MN][2], hm[MN], nxt, dd, g[MN][2], bit[MN], dist[MN];
vi adj[MN], vec; stack<int> st;

void upd(int p,int v){for(;p<=n;p+=p&-p)bit[p]+=v;}
int qu(int p){int r=0;for(;p;p-=p&-p)r+=bit[p]; return r;}

void dfs(int n,int p,int d){
    dep[n] = d; sp[n][0] = p;
    vis[n][0] = ++nxt;
    for(auto v : adj[n])
        if(v!=p) dfs(v, n, d+1);
    vis[n][1] = nxt;
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    dd = 0;
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=dep[x]-dep[y])
            x = sp[x][i], dd += (1<<i);
    }
    if(x==y) return x;
    for(int i=LG-1;i>=0;i--){
        if(sp[x][i]!=sp[y][i]){
            x = sp[x][i];
            y = sp[y][i];
            dd += (1<<(i+1));
        }
    }
    dd += 2;
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
    for(scanf("%d%d",&n,&q),i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,1);
    for(j=1;j<LG;j++){
        for(i=1;i<=n;i++)
            sp[i][j]=sp[sp[i][j-1]][j-1];
    }
    for(;q;q--){
        scanf("%d%d%d",&k,&m,&r);
        vec.clear();
        for(i=1;i<=k;i++){
            scanf("%d",&x);
            vec.pb(x);
            lca(x,r);
            dist[x] = dd;
            if(x==r) hm[x] = 1;
            else if(lca(x,r)==x){
                hm[x] = 2;
                int gg = adv(r,dep[r]-dep[x]-1);
                g[x][0]=vis[gg][0], g[x][1]=vis[gg][1];
            }
            else hm[x] = 0;
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        sort(vec.begin(),vec.end(),[](int i,int j){return dist[i]<dist[j];});
        for(auto v : vec){
            int d = qu(vis[v][0]);
            memset(tmp,0,sizeof(tmp));
            for(j=0;j<=m;j++){
                if(j){
                    tmp[j]=(tmp[j]+dp[j-1])%mod;
                    tmp[j]=(tmp[j]+1LL*dp[j]*max(0,j-d))%mod;
                }
            }
            for(j=0;j<=m;j++) dp[j]=tmp[j];
            if(hm[v]==1) upd(1,1);
            else if(hm[v]==2){
                upd(1,1); upd(g[v][0],-1);
                upd(g[v][1]+1,1);
            }
            else{
                upd(vis[v][0],1);
                upd(vis[v][1]+1,-1);
            }
        }
        for(auto v : vec){
            if(hm[v]==1) upd(1,-1);
            else if(hm[v]==2){
                upd(1,-1); upd(g[v][0],1);
                upd(g[v][1]+1,-1);
            }
            else{
                upd(vis[v][0],-1);
                upd(vis[v][1]+1,1);
            }
        }
        int ans = 0;
        for(i=0;i<=m;i++) ans=(ans+dp[i])%mod;
        printf("%d\n",ans);
    }
    return 0;
}