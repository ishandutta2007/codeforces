#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <assert.h>

using namespace std;

int main() {
//  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<string> name(n);
  vector<int> ver(n);
  vector<vector<pair<string, int>>> g(n);
  map<pair<string, int>, int> rev;
  for (int i = 0; i < n; i++) {
    cin >> name[i] >> ver[i];
    rev[pair {name[i], ver[i]}] = i;
    int sz;
    cin >> sz;
    g[i].resize(sz);
    for (int j = 0; j < sz; j++) {
      cin >> g[i][j].first >> g[i][j].second;
    }
  }
  vector<int> dst(n, -1);
  map<string, pair<int, int>> ans;
  dst[0] = 0;
  for (int cdst = 0; cdst < n; cdst++) {
    for (int i = 0; i < n; i++) {
      if (dst[i] == cdst) {
        auto pr = pair {dst[i], -ver[i]};
        auto it = ans.find(name[i]);
        if ((it == ans.end()) || ((it != ans.end()) && (pr < it->second))) {
          ans[name[i]] = pr;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dst[i] == cdst) {
        auto pr = pair {dst[i], -ver[i]};
        auto it = ans.find(name[i]);
        if ((it != ans.end()) && (it->second == pr)) {
          for (auto nv : g[i]) {
            auto it2 = rev.find(nv);
            assert(it2 != rev.end());
            int y = it2->second;
            if (dst[y] < 0) {
              dst[y] = dst[i] + 1;
            }
          }
        }
      }
    }
  }
  cout << (int)ans.size() - 1 << endl;
  for (auto a : ans) {
    if (a.first != name[0]) {
      cout << a.first << " " << -a.second.second << "\n";
    }
  }
}