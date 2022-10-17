#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
const int M = 100;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 2) {
    cout << "-1\n";
    return 0;
  }
  auto print = [](vector<vector<char>>& answer) {
    reverse(answer.begin(), answer.end());
    cout << SZ(answer) << '\n';
    for (const auto& row : answer) {
      for (auto cell : row) {
        cout << cell;
      }
      cout << '\n';
    }
  };
  for (int side = 1; side <= M; side++) {
    if (side * side < n) {
      continue;
    }
    for (int full_filled = 1; full_filled <= side && full_filled * full_filled <= n; full_filled++) {
      if (full_filled % 2 != n % 2 || 2 * full_filled * side - full_filled * full_filled < n) {
        continue;
      }
      vector<vector<char>> answer(side, vector<char>(side, '.'));
      for (int i = 0; i < full_filled; i++) {
        for (int j = 0; j < full_filled; j++) {
          answer[i][j] = 'o';
        }
      }
      int rem = n - full_filled * full_filled;
      assert(rem >= 0 && rem % 2 == 0);
      pair<int, int> nxt = {full_filled, 0};
      while (rem > 0) {
        rem -= 2;
        answer[nxt.first][nxt.second] = answer[nxt.second][nxt.first] = 'o';
        if (nxt.first + 1 < side) {
          nxt = {nxt.first + 1, nxt.second};
        }
        else {
          nxt = {full_filled, nxt.second + 1};
        }
      }
      print(answer);
      return 0;
    }
  }
  assert(false);
  return 0;
}