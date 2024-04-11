#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 + 1;

vector<int> where[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    where[a[i]].push_back(i);
  }

  tuple<long long, int, int> ans = {LLONG_MAX, 0, 0};
  for (int i = 1; i < N; ++i) {
    int u = 0, v = 0;
    for (int j = i; j < N && v == 0; j += i) {
      for (auto k : where[j]) {
        if (u == 0) {
          u = k;
        } else {
          v = k;
          break;
        }
      }
    }

    if (v > 0) {
      if (u > v) {
        swap(u, v);
      }
      ans = min(ans, {(long long) a[u] * a[v] / i, u, v});
    }
  }

  cout << get<1>(ans) << " " << get<2>(ans) << "\n";
}