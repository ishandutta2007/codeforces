#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const ll MN = 1e5+5, MM = 1e9+7;
ll N, mod, e=1, i, j, c, x, y, w, crt[MN], sz[MN], m[MN], pw[MN]={1}, t[MN], ans, inv[MN];
vector<pll> adj[MN]; queue<ll> q;
map<ll,ll> a, b;

ll qpow(ll b,ll exp){
    if(exp<=0) return 1LL;
    else if(exp&1) return b*qpow(b,exp-1)%mod;
    else{ll r=qpow(b,exp>>1); return r*r%mod;}
}

ll dfs1(ll n,ll p){
    sz[n] = 1; m[n] = 0;
    for(auto v : adj[n])
        if(v.first!=p&&!crt[v.first]) sz[n] += dfs1(v.first, n), m[n] = max(m[n], sz[v.first]);
    return sz[n];
}

void dfs2(ll n,ll p,ll s){
    if(2*m[n]<=s&&2*(s-sz[n])<=s) c=n;
    for(auto v : adj[n])
        if(v.first!=p&&!crt[v.first]) dfs2(v.first, n, s);
}

void go1(ll n,ll p,ll s,ll d){
    for(auto v : adj[n]){
        if(v.first==p){
            s = (10*s+v.second)%mod;
            break;
        }
    }
    ll h = (mod-s)*inv[d+1]%mod;
    ans += a[h];
    b[s]++;
    for(auto v : adj[n])
        if(v.first!=p&&!crt[v.first]) go1(v.first,n,s,d+1);
}

void go2(ll n,ll p,ll d){
    for(auto v : adj[n]){
        if(v.first==p){
            t[n] = (v.second*pw[d]+t[v.first])%mod;
            break;
        }
    }
    a[t[n]]++;
    for(auto v : adj[n])
        if(v.first!=p&&!crt[v.first]) go2(v.first,n,d+1);
}

void solve(ll n){
    a.clear(); b.clear(); t[n]=0;
    for(auto v : adj[n]){
        if(crt[v.first]) continue;
        go1(v.first,n,0,0);
        go2(v.first,n,0);
    }
    a.clear(); b.clear();
    for(int i=adj[n].size()-1;i>=0;i--){
        if(crt[adj[n][i].first]) continue;
        go1(adj[n][i].first,n,0,0);
        go2(adj[n][i].first,n,0);
    }
    ans += a[0]+b[0];
}

int main(){
    for(scanf("%lld%lld",&N,&mod),i=0;i<=N;i++)
        pw[i+1] = pw[i]*10%mod;
    ll res = mod;
    for(i=2;i*i<=mod;i++){
        if(res%i==0){
            while(res%i==0){
                res /= i;
                e *= i;
            }
            e /= i; e *= (i-1);
        }
    }
    if(res!=1) e *= (res-1);
    for(i=0;i<=N;i++) inv[i]=qpow(pw[i],e-1);
    for(i=1;i<N;i++){
        scanf("%lld%lld%lld",&x,&y,&w); x++; y++;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    q.push(1);
    while(q.size()){
        x = q.front(); q.pop();
        dfs1(x, 0); dfs2(x, 0, sz[x]);
        solve(c);
        crt[c] = 1;
        for(auto v : adj[c]){
            if(!crt[v.first]) q.push(v.first);
        }
    }
    printf("%lld\n",ans);
    return 0;
}