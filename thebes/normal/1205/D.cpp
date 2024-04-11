#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 1005;
int n, m, i, j, x, y, rt, nxt=1, dep[MN], sz[MN], mx[MN], dp[MN], lnk[MN], h[MN], M[2], ID[2];
struct edge{int x, y, w;}e[MN];
vector<pii> adj[MN], cc, tmp; vi chk;

int dfs(int n,int p){
    sz[n] = 1;
    for(auto v : adj[n]){
        if(v.first==p) continue;
        sz[n] += dfs(v.first, n);
        mx[n] = max(mx[n], sz[v.first]);
    }
    return sz[n];
}

void dfs2(int nn,int p){
    if(2*mx[nn]<=n&&2*(n-sz[nn])<=n) chk.pb(nn);
    for(auto v : adj[nn])
        if(v.first!=p) dfs2(v.first, nn);
}

void go(int n,int p,int id){
    e[id].w = nxt-dep[p];
    dep[n] = nxt;
    if(nxt<=m) nxt++;
    else nxt+=m+1;
    for(auto v : adj[n])
        if(v.first!=p) go(v.first,n,v.second);
}

int main(){
    for(scanf("%d",&n),i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        e[i].x = x, e[i].y = y;
        adj[x].pb({y,i});
        adj[y].pb({x,i});
    }
    m = (n-1)/2;
    if(n==2) printf("%d %d %d\n",e[1].x,e[1].y,1);
    else{
        dfs(1,0); dfs2(1,0);
        for(int r=0;r<chk.size();r++){
            int rt = chk[r];
            swap(tmp, cc); cc.clear();
            for(auto v : adj[rt]){
                dfs(v.first,rt);
                cc.pb({v.first,sz[v.first]});
            }
            memset(dp,0,sizeof(dp));
            dp[0] = 1;
            for(j=0;j<cc.size();j++){
                for(i=n;i>=cc[j].second;i--){
                    if(!dp[i]&&dp[i-cc[j].second]){
                        dp[i] = 1;
                        lnk[i] = j;
                    }
                }
            }
            int dif=1<<30, id;
            for(i=0;i<=n;i++){
                if(dp[i]&&abs(i-m)<dif){
                    dif = abs(i-m);
                    id = i;
                }
            }
            M[r] = dif; ID[r] = id;
        }
        int rt = chk[0];
        if(chk.size()==2){
            if(M[1]<M[0])
                swap(ID[0],ID[1]), rt = chk[1];
            else
                swap(cc, tmp);
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(j=0;j<cc.size();j++){
            for(i=n;i>=cc[j].second;i--){
                if(!dp[i]&&dp[i-cc[j].second]){
                    dp[i] = 1;
                    lnk[i] = j;
                }
            }
        }
        int id = ID[0];
        m = ID[0];
        while(id){
            int ii = lnk[id];
            h[cc[ii].first]=1;
            id-=cc[ii].second;
        }
        for(auto v : adj[rt]){
            if(h[v.first]) go(v.first,rt,v.second);
        }
        for(auto v : adj[rt]){
            if(!h[v.first]) go(v.first,rt,v.second);
        }
        for(i=1;i<n;i++)
            printf("%d %d %d\n",e[i].x,e[i].y,e[i].w);
    }
    return 0;
}