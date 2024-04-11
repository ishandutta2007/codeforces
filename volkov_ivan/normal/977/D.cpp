#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;
long long arr[MAX_N + 1];
vector <int> g[MAX_N + 1];
vector <long long> ans;
bool visited[MAX_N + 1];

void dfs(int v) {
    visited[v] = 1;
    for (int u : g[v]) {
        if (!visited[u]) dfs(u);
    }
    ans.push_back(arr[v]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (arr[i] == 3 * arr[j] || arr[j] == 2 * arr[i]) g[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}