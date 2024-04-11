#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

int visited[N];
int par[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int root = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> par[i];
    if (par[i] == i) {
      root = i;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (visited[i] == 0) {
      int j = i;
      while (visited[j] == 0) {
        visited[j] = i;
        j = par[j];
      }

      if (visited[j] == i && j != root) {
        if (root == 0) {
          root = j;
        }
        par[j] = root;
        ++ans;
      }
    }
  }

  cout << ans << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << par[i] << " ";
  }
  cout << "\n";
}