#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

string patterns[N];
vector<int> key[N];
int locks[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  map<string, int> id;
  for (int i = 1; i <= n; ++i) {
    cin >> patterns[i];
    id[patterns[i]] = i;
  }

  for (int i = 0; i < m; ++i) {
    int x;
    string s;
    cin >> s >> x;

    set<string> matches;
    for (int i = 0; i < (1 << k); ++i) {
      string t = s;
      for (int j = 0; j < k; ++j) {
        if ((i & (1 << j)) > 0) {
          t[j] = '_';
        }
      }
      matches.insert(t);
    }

    if (matches.count(patterns[x]) == 0) {
      cout << "NO\n";
      exit(0);
    }

    for (auto &t : matches) {
      if (id.count(t) > 0 && id[t] != x) {
        key[x].push_back(id[t]);
        ++locks[id[t]];
      }
    }
  }

  vector<int> good;
  for (int i = 1; i <= n; ++i) {
    if (locks[i] == 0) {
      good.push_back(i);
    }
  }

  vector<int> ans;
  while (!good.empty()) {
    int u = good.back();
    good.pop_back();
    ans.push_back(u);

    for (auto v : key[u]) {
      if (--locks[v] == 0) {
        good.push_back(v);
      }
    }
  }

  if ((int) ans.size() == n) {
    cout << "YES\n";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
}