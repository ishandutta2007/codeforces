#include<bits/stdc++.h>
using namespace std;
#define pop_back pob
#define make_pair mp
#define endl "\n"

const int N = 200005;
int a[N], eltour[N], l[N], r[N], cnt = 0;
vector <int> adj[N];
bool ck[N];

void dfs(int u){
    eltour[cnt] = u;
    l[u] = cnt;
    ck[u] = 1;
    for (int i = 0; i < adj[u].size(); i++){
        if (!ck[adj[u][i]]){
            cnt++;
            dfs(adj[u][i]);
        }
    }
    r[u] = cnt;
    return;
}

int main(){
    int n, q, u, k;
    cin >> n >> q;
    memset(ck, 0, sizeof(ck));
    for (int i = 2; i <= n; i++){
        cin >> a[i];
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
    }
    dfs(1);
    /*
    for (int i = 0; i < n; i++){
        cout << eltour[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << l[i] << " " << r[i] << endl;
    }
    cout << endl;
    */
    while (q--){
        cin >> u >> k;
        if (r[u] - l[u] + 1 < k){
            cout << -1 << endl;
            continue;
        }
        cout << eltour[l[u] + k - 1] << endl;
    }
}