#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;

vector<vector<int>> g(N);
vector<bool> was(N, false);

void Dfs(int v) {
  was[v] = true;
  for (auto c : g[v]) {
    if (was[c] == false) {
      was[c] = true;
      Dfs(c);
    }
  }
}

int main() {   
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    g[i].push_back(i + x);  
  }
  --k;
  Dfs(0);
  if (was[k] == true) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}