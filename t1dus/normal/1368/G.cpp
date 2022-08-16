#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define pii pair<int,int>
#define F first
#define S second

const int MX = 200005;

int n,m;
vi adj[2][MX];
int st[MX],fin[MX];
int deg[2][MX];
int ans,tim;
int cur = 1;

pii seg[4*MX];
int lazy[4*MX];

pii merge(pii x,pii y){
    if(x.F == y.F) return {x.F,x.S+y.S};
    return min(x,y);
}

void build(int node,int l,int r){
    if(l == r){
        seg[node] = {0,1};
        return;
    }
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    seg[node] = merge(seg[2*node],seg[2*node+1]);
}

void propagate(int node,int l,int r){
    seg[node].F += lazy[node];
    if(l != r){
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node,int l,int r,int x,int y,int val){
    propagate(node,l,r);
    if(l > y or r < x) return;
    if(l >= x and r <= y){
        lazy[node] += val;
        propagate(node,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(2*node,l,mid,x,y,val);
    update(2*node+1,mid+1,r,x,y,val);
    seg[node] = merge(seg[2*node],seg[2*node+1]);
}

void dfs(int u){
    st[u] = tim++;
    for(auto v:adj[1][u]){
        dfs(v);
    }
    fin[u] = tim;
}

void solve(int u){
    update(1,0,cur-1,st[u],fin[u]-1,1);
    if(!seg[1].F) ans -= seg[1].S;
    for(auto v:adj[0][u]){
        solve(v);
    }
    update(1,0,cur-1,st[u],fin[u]-1,-1);
}

signed main(){
    cin >> n >> m;
    vvi index(n,vi(m,-1)); 
    vector<vector<char> > a(n,vector<char>(m));
    REP(i,n){
        REP(j,m){
            cin >> a[i][j];
            if(a[i][j] == 'L'){
                index[i][j] = cur;
                index[i][j+1] = cur;
                cur++;
            }
            else if(a[i][j] == 'U'){
                index[i][j] = cur;
                index[i+1][j] = cur;
                cur++;
            }
        }
    }
    cur--;
    REP(i,n){
        REP(j,m){
            if(a[i][j] == 'L' and j+2 < m){
                adj[(i+j)%2][index[i][j+2]].pb(index[i][j]);
                deg[(i+j)%2][index[i][j]]++;
            }
            if(a[i][j] == 'R' and j-2 >= 0){
                adj[(i+j)%2][index[i][j-2]].pb(index[i][j]);
                deg[(i+j)%2][index[i][j]]++;
            }
            if(a[i][j] == 'U' and i+2 < n){
                adj[(i+j)%2][index[i+2][j]].pb(index[i][j]);
                deg[(i+j)%2][index[i][j]]++;
            }
            if(a[i][j] == 'D' and i-2 >= 0){
                adj[(i+j)%2][index[i-2][j]].pb(index[i][j]);
                deg[(i+j)%2][index[i][j]]++;
            }
        }
    }
    ans = (n*m*n*m)/4;
    tim = 0;
    FOR(i,1,cur+1){
        if(!deg[1][i]) dfs(i);
    }
    build(1,0,cur-1);
    FOR(i,1,cur+1){
        if(!deg[0][i]) solve(i);
    }
    cout << ans << "\n";
}