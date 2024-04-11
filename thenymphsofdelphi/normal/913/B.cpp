#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
vector <int> adj[N];
bool isl[N];
int cnt[N];

void dfs(int u){
    for (int i = 0; i < adj[u].size(); i++){
        if (!isl[adj[u][i]]){
            cnt[u]++;
        }
        dfs(adj[u][i]);
    }
    return;
}

int main(){
    cin >> n;
    int x;
    for (int i = 1; i < n; i++){
        cin >> x;
        adj[x].push_back(i + 1);
        isl[x] = 1;
    }
    dfs(1);
    for (int i = 0; i < n; i++){
        if (isl[i] && cnt[i] < 3){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}