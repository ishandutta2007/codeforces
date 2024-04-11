#include <bits/stdc++.h>
using namespace std;

int n, m;

void go(int &u, int t) {
  for (int i = t; i > 0; --i) {
    if (u < m) {
      u += i;
    } else {
      u -= i;
    }
    u += (u < 0) ? n : 0;
    u -= (u >= n) ? n : 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int s;
  long long t;
  cin >> n >> m >> s >> t;

  go(--s, t % n);
  t /= n;

  vector<int> visited(n, -1);
  vector<int> cycle = {s};
  visited[s] = 0;

  for (int i = 1; i <= t; ++i) {
    go(s, n);

    if (visited[s] != -1) {
      t -= i;
      t %= i - visited[s];
      cout << cycle[visited[s] + t] + 1 << "\n";
      exit(0);
    }

    visited[s] = i;
    cycle.push_back(s);
  }

  cout << s + 1 << "\n";
}