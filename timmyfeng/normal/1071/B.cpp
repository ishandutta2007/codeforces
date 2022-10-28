#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2001;

string grid[N];
int used[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<pair<int, int>> cur = {{0, 0}};
  vector<pair<int, int>> nxt;
  char best;

  auto process = [&](int r, int c, int cnt) {
    if (r >= n || c >= n)
      return;

    if (grid[r][c] == 'a' || cnt < k) {
      if ('a' < best) {
        best = 'a';
        nxt.clear();
        used[r][c] = INF;
      }
      used[r][c] = min(used[r][c], cnt + (grid[r][c] > 'a'));
      nxt.emplace_back(r, c);
    } else if (grid[r][c] <= best) {
      if (grid[r][c] < best) {
        best = grid[r][c];
        used[r][c] = INF;
        nxt.clear();
      }
      used[r][c] = min(used[r][c], cnt);
      nxt.emplace_back(r, c);
    }
  };

  memset(used, INF, sizeof used);
  string ans;

  if (grid[0][0] != 'a' && k > 0) {
    used[0][0] = 1;
    ans = "a";
  } else {
    used[0][0] = 0;
    ans = string(1, grid[0][0]);
  }


  for (int i = 1; i < 2 * n - 1; ++i) {
    best = 'z';
    for (auto [r, c] : cur) {
      process(r + 1, c, used[r][c]);
      process(r, c + 1, used[r][c]);
    }
    ans += best;
    nxt.resize(unique(nxt.begin(), nxt.end()) - nxt.begin());
    swap(cur, nxt);
    nxt.clear();
  }

  cout << ans << "\n";
}