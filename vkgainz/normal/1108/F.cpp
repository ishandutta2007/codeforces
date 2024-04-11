#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tab[200001][20];
int n,m;
vector<pair<int,int>> adjTree[200001];
vector<pair<int,pair<int,int>>> edges;
int par[200001], depth[200001];
int pw[200001];
int tabw[200001][20];
bool cmp(const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y){
    if(x.second.second==y.second.second){
        if(x.second.first==y.second.first)
            return x.first<y.first;
        return x.second.first<y.second.first;
    }
    return x.second.second<y.second.second;
}
void init(){
    for(int j=0;j<20;j++){
        for(int i=0;i<n;i++){
            if(j==0){
                tab[i][j] = par[i];
                tabw[i][j] = pw[i];
            }
            else{
                tab[i][j] = tab[ tab[i][j-1] ][j-1];
                tabw[i][j] = max(tabw[i][j-1], tabw[ tab[i][j-1] ][j-1]);
            }
        }
    }
}
int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    for(int j=19;j>=0;j--){
        if(depth[u]-(1<<j)>=depth[v]){
            u = tab[u][j];
        }
    }
    if(u==v) return u;
    for(int j=19;j>=0;j--){
        if(tab[u][j]!=tab[v][j]){
            u = tab[u][j];
            v = tab[v][j];
        }
    }
    return par[u];
}
int getMax(int u,int v){
    int l = lca(u,v);
    int ret =0 ;
    for(int j=19;j>=0;j--){
        if(depth[u]-(1<<j)>=depth[l]){
            ret = max(ret,tabw[u][j]);
            u = tab[u][j];
        }
    }
    for(int j=19;j>=0;j--){
        if(depth[v]-(1<<j)>=depth[l]){
            ret = max(ret,tabw[v][j]);
            v = tab[v][j];
        }
    }
    return ret;
}
void dfs(int curr,int p){
    for(auto it : adjTree[curr]){
        if(it.first!=p){
            par[it.first] = curr;
            depth[it.first] = depth[curr]+1;
            pw[it.first] = it.second;
            dfs(it.first,curr);
        }
    }
}
struct dsu{
    int parent[200001];
    int sz[200001];
    void init(int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int x){
        if(parent[x]!=x){
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }
    void merge_set(int x,int y){
        x = find_set(x);
        y = find_set(y);
        if(x!=y){
            if(sz[x]<sz[y]) swap(x,y);
            parent[y] = x;
            sz[y]+=sz[x];
        }
    }
};
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        --u; --v;
        edges.push_back({u,{v,w}});
    }
    sort(edges.begin(),edges.end(),cmp);
    dsu d;
    d.init(n);
    vector<pair<int,pair<int,int>>> other;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second.first;
        int w = edges[i].second.second;
        if(d.find_set(u)==d.find_set(v)){
            other.push_back(edges[i]);
            continue;
        }
        else{
            d.merge_set(u,v);
            adjTree[u].push_back({v,w});
            adjTree[v].push_back({u,w});
        }
    }
    dfs(0,-1);
    init();
    int ans =0 ;
    for(auto &it : other){
        int x = getMax(it.first,it.second.first);
        if(it.second.second<=x){
            ans+=x+1-it.second.second;
        }
    }
    cout << ans << endl;
}