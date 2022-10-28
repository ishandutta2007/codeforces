#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

queue<int> app[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  int ans = 0;
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> que;

  int i = 0;
  while (q--) {
    int t, x;
    cin >> t >> x;

    if (t == 1) {
      que.push({i, x - 1});
      app[x - 1].push(i++);
      ++ans;
    } else if (t == 2) {
      while (!app[x - 1].empty()) {
        app[x - 1].pop();
        --ans;
      }
    } else {
      while (!que.empty() && que.top()[0] < x) {
        auto [a, b] = que.top();
        que.pop();
        if (!app[b].empty() && app[b].front() == a) {
          app[b].pop();
          --ans;
        }
      }
    }

    cout << ans << "\n";
  }
}