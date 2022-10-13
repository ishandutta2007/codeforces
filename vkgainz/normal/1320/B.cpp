#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adjIn[200001], adj[200001];
int dist[200001];
int num[200001];
int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        --u; --v;
        adjIn[v].push_back(u);
        adj[u].push_back(v);
    }
    int k; cin >> k;
    int p[k];
    for(int i=0;i<k;i++) {
        cin >> p[i];
        --p[i];
    }
    for(int i=0;i<n;i++) dist[i] = 100000000;
    queue<int> q;
    q.push(p[k-1]);
    dist[p[k-1]] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int next : adjIn[x]){
            if(dist[x]+1<dist[next]){
                dist[next] = dist[x]+1;
                q.push(next);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j : adj[i]){
            if(dist[j]+1==dist[i]){
                ++num[i];
            }

        }
    }
    int min = 0;
    int max = 0;
    for(int i=0;i<k-1;i++){
        if(dist[p[i+1]]+1==dist[p[i]]){
            if(num[p[i]]>=2) ++max;
        }
        else{
            ++min; ++max;
        }
    }
    cout << min << " " << max << endl;
}