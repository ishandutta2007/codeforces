#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;

const int N = 5000;

bool used[N];
point a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i] = point(x, y);
  }

  int u = 0;
  used[u] = true;
  cout << u + 1 << " ";
  for (int i = 1; i < n; ++i) {
    long long dist = 0;
    int v = -1;

    for (int j = 0; j < n; ++j) {
      if (!used[j] && norm(a[j] - a[u]) > dist) {
        dist = norm(a[j] - a[u]);
        v = j;
      }
    }

    u = v;
    used[u] = true;
    cout << u + 1 << " ";
  }
  cout << "\n";
}