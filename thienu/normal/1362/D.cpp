#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

int mex(set<int> s){
    int m = 0;
    while(s.find(m) != s.end())
        m++;
    return m;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> order;
    vector<int> linear_desired(n);
    vector<vector<int>> desired(n, vector<int>());
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        x--;
        desired[x].push_back(i);
        linear_desired[i] = x;
    }
    for(int i = 0; i < n; i++){
        for(int j : desired[i]){
            set<int> adj_vals;
            for(int other : adj[j]){
                adj_vals.insert(linear_desired[other]);
            }
            if(mex(adj_vals) != i){
                goto end;
            }
            order.push_back(j+1);
        }
    }
    for(int i = 0; i < n; i++){
        cout << order[i] << " ";
    }
    cout << endl;
    exit(0);
    end:
    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}