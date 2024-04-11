#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void find_children(int bef, int n, vector<vector<int>> &children, vector<vector<int>> &adj){
    for(int a : adj[n]){
        if(a != bef){
            children[n].push_back(a);
            find_children(n, a, children, adj);
        }
    }
}

int num_children(int n, vector<vector<int>> &children){
    int ans = 0;
    for(int a : children[n]){
        ans += num_children(a, children);
    }
    return ans + 1;
}

void solve(){
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> children(n, vector<int>());
    find_children(-1, x, children, adj);
    if(children[x].size() <= 1){
        cout << "Ayush" << endl;
    }
    else{
        int num_odds = 0;
        for(int a : children[x]){
            // cout << "subtree " << a << " " << num_children(a, children) << endl;
            if(num_children(a, children) & 1){
                num_odds++;
            }
        }
        cout << ((num_odds & 1) ? "Ayush" : "Ashish") << endl;
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}