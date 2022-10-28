#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> up(n), down(n);
  for (int i = 1; i < n; ++i) {
    cin >> up[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> down[i];
  }

  for (int i = 1; i < n; ++i) {
    down[n - 1 - i] += down[n - i];
    up[i] += up[i - 1];
  }

  vector<int> dist(n);
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    dist[i] = up[i] + b + down[i];
  }
  sort(dist.begin(), dist.end());

  cout << dist[0] + dist[1] << "\n";
}