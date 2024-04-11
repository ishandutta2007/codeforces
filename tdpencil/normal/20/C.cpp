#include<bits/stdc++.h>
using namespace std;
// lmao imagine copying my code, if you have then
// no hard feeligns but like
// lmao

// lol


//um okay
const int mxN = 2e5;
using ll = long long;
vector<pair<ll, ll>> adjList[mxN];
ll dist[mxN];
bool visited[mxN];
ll path[mxN];
int main() {
    ll n, m;
    cin >> n >> m;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
    for(int i =0; i < m; i++) {
        ll a, b, cost;
        cin >> a >> b >> cost;
        --a, --b;
        adjList[a].push_back({cost, b});
        adjList[b].push_back({cost, a});
    }

    for(int i =0; i <n; i++) path[i]=-1;
    for(int i = 1; i < n; i++) dist[i]=10000000000000;
    dist[0]=0;
    pq.push({0, 0});
    stack<ll> s;    
    while(pq.size()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node]=true;
        for(auto &e: adjList[node]) {
            if(dist[e.second] > dist[node] + e.first) {
                dist[e.second]=dist[node]+e.first;
                pq.push({dist[e.second], e.second});
                path[e.second]=node;
            }
        }   
    }
    ll a=n-1;
    if(path[a]==-1) {
        cout << -1 << '\n';
        return 0;
    }
    
    while(a != -1) {
        s.push(a);
        a = path[a];
    }
    while(s.size()) {
        int t = s.top();
        s.pop();
        cout << t+1 << ' ';
    }
}