#include <bits/stdc++.h>
using namespace std;

const int N = 100;

vector<int> rows;
vector<int> cols;
int g[N][N];
int n, m;

void process_rows() {
  for (int i = 0; i < n; ++i) {
    int cnt = *min_element(g[i], g[i] + m);
    for (int j = 0; j < m; ++j) {
      g[i][j] -= cnt;
    }
    for (int j = 0; j < cnt; ++j) {
      rows.push_back(i);
    }
  }
}

void process_cols() {
  for (int i = 0; i < m; ++i) {
    int cnt = g[0][i];
    for (int j = 0; j < n; ++j) {
      cnt = min(cnt, g[j][i]);
    }
    for (int j = 0; j < n; ++j) {
      g[j][i] -= cnt;
    }
    for (int j = 0; j < cnt; ++j) {
      cols.push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  if (n < m) {
    process_rows();
    process_cols();
  } else {
    process_cols();
    process_rows();
  }

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    ok &= (*max_element(g[i], g[i] + m) == 0);
  }

  if (!ok) {
    cout << -1 << "\n";
  } else {
    cout << rows.size() + cols.size() << "\n";
    for (auto i : rows) {
      cout << "row " << i + 1 << "\n";
    }
    for (auto i : cols) {
      cout << "col " << i + 1 << "\n";
    }
  }
}