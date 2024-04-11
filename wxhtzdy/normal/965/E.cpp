/**
 *    author:  wxhtzdy
 *    created: 24.01.2022 17:25:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> trie(1, vector<int>(26, -1));
  vector<bool> f(1);
  for (int i = 0; i < n; i++) {
    int t = 0;
    for (int j = 0; j < (int) s[i].size(); j++) {
      int c = s[i][j] - 'a';
      if (trie[t][c] == -1) {
        trie[t][c] = (int) trie.size();
        trie.push_back(vector<int>(26, -1));
        f.push_back(false);
      }
      t = trie[t][c];
    }
    f[t] = true;
  }
  vector<multiset<int>> d(trie.size());
  function<void(int, int)> Solve = [&](int v, int dep) { 
    for (int i = 0; i < 26; i++) {
      int u = trie[v][i];
      if (u != -1) {
        Solve(u, dep + 1);
        if (d[v].size() < d[u].size()) {
          swap(d[v], d[u]);
        }
        for (int x : d[u]) {
          d[v].insert(x);
        }
      }
    }       
    if (v == 0) {
      return;
    }
    if (f[v]) {
      d[v].insert(dep);
    } else {
      d[v].erase(prev(d[v].end()));
      d[v].insert(dep); 
    }
  };   
  Solve(0, 0);
  cout << accumulate(d[0].begin(), d[0].end(), 0LL) << '\n';                                             
  return 0;
}