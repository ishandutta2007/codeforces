#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> st(n), ed(n);
  for (int i = 0; i < n; ++i) {
    cin >> st[i] >> ed[i];
    st[i]--, ed[i]--;
  }
  map<vector<int>, int> mp;
  vector<vector<int>> stat;
  function<void(vector<int>)> Dfs = [&](vector<int> a) {
    sort(a.begin(), a.end());
    if (mp.find(a) == mp.end()) {
      mp[a] = stat.size();
      stat.push_back(a);
    }
    if (a.size() == 4) return;
    for (int i = 0; i < 9; ++i) {
      a.push_back(i);
      Dfs(a);
      a.pop_back();
    }
  };

  Dfs(vector<int>());

  const int kM = 715;
  vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(9, vector<int>(kM, -1)));
  vector<vector<int>> add(kM, vector<int>(9, -1));
  vector<vector<int>> sub(kM, vector<int>(9, -1));
  for (int i = 0; i < kM; ++i) {
    for (int g = 0; g < 9; ++g) {
      vector<int> d = stat[i];
      d.push_back(g);
      sort(d.begin(), d.end());
      if (mp.find(d) != mp.end()) add[i][g] = mp[d];
    }
  }
  for (int i = 0; i < kM; ++i) {
    for (int g = 0; g < 9; ++g) {
      vector<int> d = stat[i];
      auto it = find(d.begin(), d.end(), g);
      if (it != d.end()) {
        d.erase(it);
        if (mp.find(d) != mp.end()) sub[i][g] = mp[d];
      }
    }
  }
  dist[0][0][0] = 0;
  vector<tuple<int, int, int>> que(1, make_tuple(0, 0, 0));
  for (int it = 0; it < que.size(); ++it) {
    int a = get<0>(que[it]);
    int b = get<1>(que[it]);
    int c = get<2>(que[it]);
    if (b > 0 && dist[a][b - 1][c] == -1) {
      dist[a][b - 1][c] = dist[a][b][c] + 1;
      que.emplace_back(a, b - 1, c);
    }
    if (b + 1 < 9 && dist[a][b + 1][c] == -1) {
      dist[a][b + 1][c] = dist[a][b][c] + 1;
      que.emplace_back(a, b + 1, c);
    }
    if (a < n && stat[c].size() < 4 && st[a] == b && dist[a + 1][b][add[c][ed[a]]] == -1) {
      dist[a + 1][b][add[c][ed[a]]] = dist[a][b][c] + 1;
      que.emplace_back(a + 1, b, add[c][ed[a]]);
    }
    if (sub[c][b] != -1 && dist[a][b][sub[c][b]] == -1) {
      dist[a][b][sub[c][b]] = dist[a][b][c] + 1;
      que.emplace_back(a, b, sub[c][b]);
    }
  }
  int ans = 1'000'000'000;
  for (int i = 0; i < 9; ++i) {
    if (dist[n][i][0] != -1) ans = min(ans, dist[n][i][0]);
  }
  cout << ans << "\n";
}