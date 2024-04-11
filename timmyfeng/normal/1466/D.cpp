#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int w[N], degree[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> w[i];
    }

    fill(degree, degree + n, -1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      ++degree[u - 1], ++degree[v - 1];
    }

    vector<int> delta;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < degree[i]; ++j) {
        delta.push_back(w[i]);
      }
    }
    sort(delta.rbegin(), delta.rend());

    long long ans = accumulate(w, w + n, 0LL);
    cout << ans << " ";
    for (auto i : delta) {
      ans += i;
      cout << ans << " ";
    }
    cout << "\n";
  }
}