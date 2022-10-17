#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct Item{
    int v, deg;
    bool operator<(const Item &other) const{
        return deg > other.deg;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> b(N+1);
        int k = 0;
        for (int i = 1; i <= N; ++i){
            cin >> b[i];
            if (b[i] > i) k = i;
        }
        cout << k << '\n';
        vector<bool> rt(N+1);
        vector<vector<int>> adj(N+1);
        priority_queue<Item> pq;
        for (int i = 1; i <= N; ++i){
            if (b[i] == 0 || b[i] == N + 1){
                rt[i] = 1;
            }
            else{
                adj[b[i]].push_back(i);
            }
        }
        for (int i = 1; i <= N; ++i){
            if (rt[i]){
                pq.push({i, (int)adj[i].size()});
            }
        }
        vector<int> a;
        while (!pq.empty()){
            int v = pq.top().v; pq.pop();
            a.push_back(v);
            for (int x : adj[v]){
                pq.push({x, (int)adj[x].size()});
            }
        }
        for (int x : a) cout << x << " ";
        cout << '\n';
    }
}