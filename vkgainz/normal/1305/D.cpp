#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> adj;
int dist[1001][1001];
set<int> posRoot;
int query(int u,int v){
    ++u; ++v;
    cout << "? " << u  << " " << v << endl;
    cout.flush();
    int lca; cin >> lca;
    return --lca;
}
void upd(int c,int p){
    posRoot.erase(c);
    for(int next : adj[c]){
        if(next!=p) upd(next,c);
    }
}
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++)
        adj.push_back(vector<int>());
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++)
        posRoot.insert(i);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) dist[i][j] = 1000000000;
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int next : adj[x]){
                if(dist[i][x]+1<dist[i][next]){
                    dist[i][next] = dist[i][x]+1;
                    q.push(next);
                }
            }
        }
    }
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            pq.push(make_pair(dist[i][j],make_pair(i,j)));
    while(posRoot.size()>1){
        auto x = pq.top();
        pq.pop();
        if(posRoot.count(x.second.first) && posRoot.count(x.second.second)){
            int lca = query(x.second.first,x.second.second);
            for(int r : adj[lca]){
                if(dist[r][x.second.first]<dist[lca][x.second.first])
                    upd(r,lca);
                if(dist[r][x.second.second]<dist[lca][x.second.second])
                    upd(r,lca);
            }
        }
    }
    auto x = posRoot.begin();
    cout << "! " << ((*x)+1) << endl;
    cout.flush();
}