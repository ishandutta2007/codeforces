#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 2e5+5;
int N, i, arr[MN], x, y, down[MN], dep[MN], par[MN], fl, ans, cnt, nxt, st[3*MN];
vi adj[MN], vec[MN]; map<int,int> mp; pii vis[MN];

void upd(int i,int s,int e,int idx,int val){
    if(s^e){
        if((s+e)/2<idx) upd(2*i+1,(s+e)/2+1,e,idx,val);
        else upd(2*i,s,(s+e)/2,idx,val);
        st[i] = st[2*i]+st[2*i+1];
    }
    else st[i] = val;
}

int qu(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return qu(2*i,s,(s+e)/2,ss,se)+qu(2*i+1,(s+e)/2+1,e,ss,se);
}

void dfs(int n,int p,int d){
    par[n] = p; dep[n] = d;
    vis[n].F = ++nxt;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs(v, n, d+1);
    }
    vis[n].S = nxt;
}

void solve(int n,int p){
    if(down[n]+fl==0) ans++;
    for(auto v : adj[n]){
        if(v==p) continue;
        down[v] += down[n];
        solve(v, n);
    }
}

int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&arr[i]);
        if(!mp.count(arr[i])) mp[arr[i]]=++cnt;
        vec[mp[arr[i]]].push_back(i);
    }
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0, 0);
    for(int j=1;j<=cnt;j++){
        sort(vec[j].begin(),vec[j].end(),[](int i,int j){return dep[i]>dep[j];});
        for(auto u : vec[j]){
            int sub = qu(1,1,N,vis[u].F,vis[u].S);
            if(sub+1!=vec[j].size()) down[u]++;
            for(auto v : adj[u]){
                if(v==par[u]) continue;
                if(qu(1,1,N,vis[v].F,vis[v].S)){
                    fl ++;
                    down[v] --;
                }
            }
            upd(1,1,N,vis[u].F,1);
        }
        for(auto u : vec[j])
            upd(1,1,N,vis[u].F,0);
    }
    solve(1, 0);
    printf("%d\n",ans);
    return 0;
}