#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> adj[N];
int color[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> prv;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    vector<int> cur(l);
    for (auto& i : cur) {
      cin >> i;
      --i;
    }

    int j = 0;
    while (j < int(min(cur.size(), prv.size())) && cur[j] == prv[j]) {
      ++j;
    }

    if (j != int(prv.size())) {
      if (j == int(cur.size())) {
        cout << "No\n";
        exit(0);
      } else if (prv[j] > cur[j]) {
        color[prv[j]] |= 2;
        color[cur[j]] |= 1;
      } else {
        adj[cur[j]].push_back(prv[j]);
      }
    }
    prv = cur;
  }

  for (int i = m - 1; i >= 0; --i) {
    for (auto c : adj[i]) {
      color[c] |= color[i] & 2;
    }
  }

  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    if (color[i] == 3) {
      cout << "No\n";
      exit(0);
    } else if (color[i] == 2) {
      ans.push_back(i);
    }
  }

  cout << "Yes\n";
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}