#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> leaf(n);
    vector<vector<int>> adj(n);
    vector<bool> work(n);
    for(int i = 0; i < n - 1; i++) {
        int p; cin >> p;
        --p;
        adj[p].push_back(i + 1);
    }

    for(int i = 0; i < n; i++)
        if(adj[i].empty())
            leaf[i] = true;
    for(int i = 0; i < n; i++) {
        int num = 0;
        for(int j : adj[i])
            if(leaf[j])
                ++num;
        if(num >= 3)
            work[i] = true;
    }
    for(int i = 0; i < n; i++)
        if(!leaf[i] && !work[i]) {
            cout << "No" << "\n";
            return 0;
        }
    cout << "Yes" << "\n";
}