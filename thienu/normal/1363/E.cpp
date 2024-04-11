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

void update_total_change(int n, vector<vector<int>> &children, vector<int> &total_change, vector<int> &pairs, vector<int> &change){
    int sum = 0;
    int pos = 0;
    int neg = 0;
    for(int i : children[n]){
        update_total_change(i, children, total_change, pairs, change);
        sum += total_change[i];
        if(total_change[i] > 0){
            pos += total_change[i];
        }
        else{
            neg -= total_change[i];
        }
    }
    sum += change[n];
    if(change[n] > 0){
        pos += change[n];
    }
    else{
        neg -= change[n];
    }
    pairs[n] = min(pos, neg);
    total_change[n] = sum;
}

void update_costs(int n, vector<vector<int>> &children, vector<int> &costs){
    for(int i : children[n]){
        if(costs[i] > costs[n]){
            costs[i] = costs[n];
        }
        update_costs(i, children, costs);
    }
}

// ll get_answer(int n, int change_made, vector<vector<int>> &children, vector<int> &costs, vector<int> &total_change, vector<int> &change){
    
// }

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> costs(n);
    vector<int> change(n);
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        costs[i] = a;
        change[i] = c-b;
    }
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
    find_children(-1, 0, children, adj);

    vector<int> total_change(n);
    vector<int> pairs(n);
    update_total_change(0, children, total_change, pairs, change);

    if(total_change[0] == 0){

        update_costs(0, children, costs);

        // for(int i = 0; i < n; i++){
        //     printf("i=%d change=%d pairs=%d cost=%d\n", i, total_change[i], pairs[i], costs[i]);
        // }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += (ll) costs[i] * (ll) pairs[i] * 2;
        }
        cout << ans << endl;

    }
    else{
        cout << -1 << endl;
    }
}

int main(){
    solve();
}