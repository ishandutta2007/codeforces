#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int depth[100001];
int par[100001];
int tab[100001][17];
int ans[100001];
int n;
map<pair<int,int>,int> idx;
void dfs2(int c,int p){
    for(int next : adj[c]) {
        if(next!=p) {
            dfs2(next,c);
            ans[c]+=ans[next];
        }
    }
}
void dfs(int c,int p){
    par[c] = p;
    if(p!=-1) depth[c] = depth[p]+1;
    for(int next : adj[c]){
        if(next!=p){
            dfs(next,c);
        }
    }
}
void init(){
    for(int j=0;j<=16;j++){
        for(int i=0;i<n;i++){
            if(j==0){
                tab[i][j] = par[i];
            }
            else{
                tab[i][j] = tab[tab[i][j-1]][j-1];
            }
        }
    }
}
int getLCA(int x,int y){
    if(depth[x]<depth[y]){
        swap(x,y);
    }
    for(int j=16;j>=0;j--){
        if(depth[x]-(1<<j)>=depth[y]){
            x = tab[x][j];
        }
    }
    if(x==y) return y;
 
    for(int j=16;j>=0;j--){
        if(tab[x][j]!=tab[y][j]){
            x = tab[x][j];
            y = tab[y][j];
        }
    }
    return tab[x][0];
}
int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        idx[make_pair(x,y)] = i, idx[make_pair(y,x)] = i;
    }
    dfs(0,-1);
    init();
    int k; cin >> k;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        int l = getLCA(x,y);
        ans[x]++;
        ans[y]++;
        ans[l]-=2;
    }
    dfs2(0,-1);
    int ret[n-1];
    for(int i=0;i<n;i++) {
        if(par[i]!=-1) {
            ret[idx[make_pair(i,par[i])]] = ans[i];
        }
    }
    for(int i=0;i<n-1;i++) cout << ret[i] << endl;
}