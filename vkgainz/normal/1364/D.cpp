#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[100001];
int depth[100001];
int par[100001];
int n,m,k;
bool found = false;
int color[100001];
vector<int> one;
vector<int> two;
void dfsbipartite(int i){
    if(color[i]==1) one.push_back(i);
    else two.push_back(i);
    for(int next : adj[i]){
        if(color[next]==0){
            color[next] = 3-color[i];
            dfsbipartite(next);
        }
    }
}
void dfs(int i){
    if(found) return;
    for(int next : adj[i]){
        if(depth[next]>0 && par[i]!=next && !found){
            found = true;
            if(depth[i]-depth[next]+1 <=k){
                cout << 2 << endl;
                cout << (depth[i]-depth[next]+1) << endl;
                while(i>=0 && depth[i]>=depth[next]){
                    cout << i+1 << " ";
                    i = par[i];
                }
                //print entire cycle
            }
            else{
                cout << 1 << endl;
                int x = (k+1)/2;
                i = par[i];
                while(x--){
                    cout << (i+1) << " ";
                    if(x==0) break;
                    i = par[par[i]];
                }
            }
        }
    }
    if(found) return;
    for(int next : adj[i]){
        if(depth[next]==0){
            par[next] = i;
            depth[next] = depth[i]+1;
            dfs(next);
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0] = 1;
    par[0] = -1;
    dfs(0);
    if(!found){
        color[0] = 1;
        dfsbipartite(0);
        cout << 1 << endl;
        if(one.size()>=(k+1)/2){
            for(int i=0;i<(k+1)/2;i++){
                cout << one[i]+1 << " ";
            }
        }
        else{
            for(int i=0;i<(k+1)/2;i++){
                cout << two[i]+1 << " ";
            }
        }
    }
}