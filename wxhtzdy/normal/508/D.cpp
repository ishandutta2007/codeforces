/**
 *    author:  wxhtzdy
 *    created: 13.06.2022 18:05:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;          
  map<string, vector<string>> g;
  map<string, int> in;
  map<string, int> out;
  vector<string> all;  
  map<string, int> cc;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string x = "";
    string y = "";
    x += s[0];
    x += s[1];
    y += s[1];
    y += s[2];
    g[x].push_back(y);
    in[x] += 1;
    out[y] += 1;
    all.push_back(x);
    all.push_back(y);
    cc[s] += 1;
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  string s;
  {
    int cnt = 0;
    for (auto &str : all) {
      if (in[str] > out[str]) {
        s = str;
        cnt += 1;
      }
    }
    if (cnt > 1) {
      cout << "NO" << '\n';
      return 0;
    }
    if (cnt == 0) {
      s = all[0];
    }
  }
  vector<string> path;
  map<string, int> ptr;
  function<void(string)> Dfs = [&](string str) {
    while (!g[str].empty()) {
      string to = g[str].back();
      g[str].pop_back();
      Dfs(to);
    }
    path.push_back(str);
  };
  Dfs(s);
  reverse(path.begin(), path.end());
  string ans = path[0];
  for (int i = 1; i < (int) path.size(); i++) {
    ans += path[i][1];
  }
  if ((int) ans.size() != n + 2) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < (int) ans.size() - 2; i++) {
    string str = "";
    str += ans[i];
    str += ans[i + 1];
    str += ans[i + 2];
    if (cc[str] == 0) {
      cout << "NO" << '\n';
      return 0;  
    }
    cc[str] -= 1;
  }
  cout << "YES" << '\n';
  cout << ans << '\n';                                
  return 0;
}