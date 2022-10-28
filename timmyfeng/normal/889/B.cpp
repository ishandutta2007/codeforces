#include <bits/stdc++.h>
using namespace std;

const int A = 26;

set<int> adj[A];
bool need[A];
int color[A];
int cnt[A];

void dfs(int u) {
  if (adj[u].size() > 1u) {
    cout << "NO\n";
    exit(0);
  }

  color[u] = 1;
  for (auto c : adj[u]) {
    ++cnt[c];
    if (color[c] == 1) {
      cout << "NO\n";
      exit(0);
    } else if (color[c] == 0) {
      dfs(c);
    }
  }
  color[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    for (auto &j : s) {
      j -= 'a';
      need[j] = true;
    }

    for (int j = 1; j < int(s.size()); ++j) {
      adj[s[j - 1]].insert(s[j]);
    }
  }

  for (int i = 0; i < A; ++i) {
    if (need[i] && color[i] == 0) {
      dfs(i);
    }
  }

  if (*max_element(cnt, cnt + A) > 1) {
    cout << "NO\n";
    exit(0);
  }

  for (int i = 0; i < A; ++i) {
    if (need[i] && cnt[i] == 0) {
      int j = i;
      while (!adj[j].empty()) {
        cout << char(j + 'a');
        j = *adj[j].begin();
      }
      cout << char(j + 'a');
    }
  }
  cout << "\n";
}