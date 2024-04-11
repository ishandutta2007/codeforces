#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

vector<int> adj[N];
int lights[N];

void dfs(int u) {
  lights[u] = adj[u].empty();
  for (auto c : adj[u]) {
    dfs(c);
    lights[u] += lights[c];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }

  dfs(0);
  sort(lights, lights + n);

  for (int i = 0; i < n; ++i) {
    cout << lights[i] << " ";
  }
  cout << "\n";
}