#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define FORD(i,a,b) for(int i = a; i >= b; i --)
#define vi vector<int>
#define pb push_back

const int MX = 150005;
const int MOD = 998244353;

int n,q;
vi adj[MX];
int tim;
int par[MX][21],dep[MX],st[MX],fin[MX],sz[MX];
int bigsum[MX],seg[2*MX];
vi big;
int BLOCK = 500;

int power(int x,int y){
    if(y == 0) return 1;
    if(y == 1) return x;
    if(y%2) return (x*power(x,y-1))%MOD;
    int p = power(x,y/2);
    return (p*p)%MOD;
}

void dfs(int u,int p,int d){
    par[u][0] = p;
    dep[u] = d;
    st[u] = tim++;
    sz[u] = 1;
    for(auto v:adj[u]){
        if(v != p){
            dfs(v,u,d+1);
            sz[u] += sz[v];
        }
    }
    fin[u] = tim;
}

void update(int l,int r,int val){
    l += n;
    r += n;
    while(l < r){
        if(l%2){
            seg[l] = (seg[l]+val)%MOD;
            l++;
        }
        if(r%2){
            --r;
            seg[r] = (seg[r]+val)%MOD;
        }
        l /= 2;
        r /= 2;
    }
}

int query(int pos){
    pos += n;
    int res = 0;
    while(pos){
        res = (res+seg[pos])%MOD;
        pos /= 2;
    }
    return res;
}

signed main(){
    cin >> n >> q;
    REP(i,n-1){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    tim = 0;
    dfs(1,1,0);
    FOR(j,1,21){
        FOR(i,1,n+1) par[i][j] = par[par[i][j-1]][j-1];
    }
    FOR(i,1,n+1){
        if((int)adj[i].size() > BLOCK) big.pb(i);
    }
    int mi = power(n,MOD-2);
    REP(i,q){
        int type,u; cin >> type >> u;
        if(type == 1){
            int d; cin >> d;
            if((int)adj[u].size() > BLOCK){
                bigsum[u] = (bigsum[u]+d)%MOD;
                continue;
            }
            update(st[u],st[u]+1,(d*n)%MOD);
            for(auto v:adj[u]){
                if(v != par[u][0])
                    update(st[v],fin[v],(d*(n-sz[v]))%MOD);
            }          
            update(0,st[u],(d*sz[u])%MOD);
            update(fin[u],n,(d*sz[u])%MOD);
        }
        else{
            int ans = query(st[u]);
            for(auto x:big){
                if(u == x) ans = (bigsum[x]*n+ans)%MOD;
                else if(st[u] < st[x] or st[u] >= fin[x]){
                    ans = (ans+bigsum[x]*sz[x])%MOD;
                }
                else{
                    int cur = u;
                    FORD(j,20,0){
                        if(dep[cur]-(1<<j) > dep[x]) cur = par[cur][j];
                    }
                    ans = (ans+bigsum[x]*(n-sz[cur]))%MOD;
                }
            }
            cout << (ans*mi)%MOD << "\n";
        }
    }
}