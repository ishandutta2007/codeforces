#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
const int INF = 1e8;

int points[4];
int x[N];
int y[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  points[0] = min_element(x, x + n) - x;
  points[1] = max_element(x, x + n) - x;
  points[2] = min_element(y, y + n) - y;
  points[3] = max_element(y, y + n) - y;

  int ans = (x[points[1]] + y[points[3]] - x[points[0]] - y[points[2]]) * 2;

  int ans3 = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      int u = points[i];
      int v = points[j];
      for (int k = 0; k < n; ++k) {
        ans3 = max(ans3,
            max({x[u], x[v], x[k]}) +
            max({y[u], y[v], y[k]}) -
            min({x[u], x[v], x[k]}) -
            min({y[u], y[v], y[k]})
        );
      }
    }
  }
  ans3 *= 2;

  for (int i = 3; i <= n; ++i) {
    cout << (i == 3 ? ans3 : ans) << " ";
  }
  cout << "\n";
}