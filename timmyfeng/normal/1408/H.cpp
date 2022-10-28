#include <bits/stdc++.h>
using namespace std;

const int N = 500'000;

int indices[N];
int prefix[N];
int suffix[N];
int a[N];

void solve() {
  int n;
  cin >> n;

  vector<int> zeroes;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (--a[i] == -1) {
      zeroes.push_back(i);
    }
  }

  if (zeroes.size() % 2 == 1) {
    zeroes.erase(zeroes.begin() + zeroes.size() / 2);
  }
  int count0 = zeroes.size();

  fill(prefix, prefix + n, 0);
  fill(suffix, suffix + n, 0);

  for (int i = 1; i <= count0 / 2; ++i) {
    for (int j = zeroes[i - 1]; j < zeroes[i]; ++j) {
      if (a[j] != -1) {
        prefix[a[j]] = i;
      }
    }

    for (int j = zeroes[count0 - i - 1]; j < zeroes[count0 - i]; ++j) {
      if (a[j] != -1) {
        suffix[a[j]] = i;
      }
    }
  }

  iota(indices, indices + n, 0);
  sort(indices, indices + n, [&](int i, int j) {
    return suffix[i] > suffix[j];
  });

  int ans = 0;
  priority_queue<int, vector<int>, greater<int>> endpoints;
  for (int i = -count0 / 2, j = 0; i <= count0 / 2; ++i) {
    while (j < n && suffix[indices[j]] == -i) {
      endpoints.push(prefix[indices[j]]);
      ++j;
    }

    while (!endpoints.empty() && endpoints.top() <= i) {
      endpoints.pop();
    }

    if (!endpoints.empty()) {
      endpoints.pop();
      ++ans;
    }
  }

  cout << min(ans, count0 / 2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}