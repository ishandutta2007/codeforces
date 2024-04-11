#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<int,int>,vector<int>> idx;
vector<int> adj[100001];
int deg[100001];
int w[100001];
int n,m;
set<int> in;
set<pair<int,int>> seen;
bool processed[100001];
vector<int> ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        idx[make_pair(u,v)].push_back(i);
        idx[make_pair(v,u)].push_back(i);
        ++deg[u];
        ++deg[v];
    }
    for(int i=0;i<n;i++){
        if(deg[i]<=w[i]){
            processed[i] = true;
            in.insert(i);
        }
    }
    int numProcessed = 0;
    while(numProcessed<n){
        if(in.empty()) break;
        auto it = in.begin();
        ++numProcessed;
        for(int next : adj[(*it)]){
            if(seen.count(make_pair((*it),next))){

            }
            else{
                for(auto &x : idx[make_pair((*it),next)])
                    ans.push_back(x);
                seen.insert(make_pair((*it),next));
                seen.insert(make_pair(next,(*it)));
            }
            --deg[next];
            if(!processed[next] && deg[next]<=w[next]){
                processed[next] = true;
                in.insert(next);
            }
        }
        in.erase(it);
    }
    reverse(ans.begin(),ans.end());
    if(numProcessed!=n){
        cout << "DEAD" << endl;
    }
    else{
        cout << "ALIVE" << endl;
        for(auto &it : ans)
            cout << it+1 << " ";
    }
}