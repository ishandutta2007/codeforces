#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

void solve() {
  vector<string> g;
  int n, m;
  cin >> n >> m;
  g.resize(n);
  for(int i = 0; i < n; i++) cin >> g[i];
  bool good = true;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(g[i][j] == '*') {
        continue;
      }
      int val = 0;
      if(g[i][j] >= '1' && g[i][j] <= '8') val = g[i][j] - '0';
      for(int dx = -1; dx <= 1; dx++) for(int dy = -1; dy <= 1; dy++) {
        int nx = i + dx;
        int ny = j + dy;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '*') val--;
      }
      if(val != 0) good = false;
    }
  }
  if(good) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}