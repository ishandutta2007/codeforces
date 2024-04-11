#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  vector<int> dist(N + 1, -1);
  vector<pair<int, int>> from(N + 1, make_pair(-1, -1));
  vector<int> que(1, N);
  dist[N] = 0;
  set<int> s;
  for (int i = 1; i < N; ++i) {
    s.insert(i);
  }
  for (int it = 0; it < que.size(); ++it) {
    int x = que[it];
    assert(x > 0);
    if (x - A[x - 1] <= 0) {
      assert(dist[0] == -1);
      dist[0] = dist[x] + 1;
      from[0] = make_pair(x, x);
      break;
    }
    auto iter = s.lower_bound(x - A[x - 1]);
    while (iter != s.end() && *iter < x) {
      int y = *iter;
      if (dist[y + B[y - 1]] == -1) {
        dist[y + B[y - 1]] = dist[x] + 1;
        from[y + B[y - 1]] = make_pair(x, x - y);
        que.push_back(y + B[y - 1]);
      }
      iter = s.erase(iter);
    }
  }
  cout << dist[0] << "\n";
  if (dist[0] != -1) {
    int x = 0;
    vector<int> res;
    while (from[x].first != -1) {
      int y = from[x].second;
      x = from[x].first;
      res.push_back(x - y);
    }
    while (!res.empty()) {
      cout << res.back() << " ";
      res.pop_back();
    }
    cout << "\n";
  }
  return 0;
}