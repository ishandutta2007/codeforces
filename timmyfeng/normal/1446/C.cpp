#include <bits/stdc++.h>
using namespace std;

const int N = 6000000;
const int L = 30;

int to[N][2];
int sub[N];

string cur;
int dfs(int u) {
  vector<int> child;
  for (auto c : to[u]) {
    if (c != 0) {
      child.push_back(dfs(c));
      sub[u] += sub[c];
    }
  }

  if (child.empty()) {
    return 0;
  } else if (child.size() == 1u) {
    return child[0];
  } else {
    return min(
        child[0] + sub[to[u][1]] - 1,
        child[1] + sub[to[u][0]] - 1
    );
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int size = 1;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    int cur = 0;
    for (int j = L - 1; j >= 0; --j) {
      int bit = (a & (1 << j)) > 0;
      if (to[cur][bit] == 0) {
        to[cur][bit] = size++;
      }
      cur = to[cur][bit];
    }
    ++sub[cur];
  }

  cout << dfs(0) << "\n";
}