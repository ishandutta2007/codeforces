/*input
1
67 50
6
4 50
90 90
20 0
0 75
78 50
80 100
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
// const int N =;

const int lScore = 200;
const int lMatch = 3;
class PreAns {

public:
  pair<int, int> dp[205][205][4][4];

  void operator()() {
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = {0, 0};

    auto updateState = [&](int x, int y, int nWin, int nLose) {
      auto update = [&](int xScore, int yScore) {
        int win = (xScore > yScore);
        dp[x + xScore][y + yScore][nWin + win][nLose + (1 - win)] = {xScore,
                                                                     yScore};
      };

      int mnScore = ((nWin == 2 && nLose == 2) ? 15 : 25);
      loop(xScore, 0, lScore) {
        auto yScore = max(mnScore, xScore + 2);
        if (x + xScore > lScore)
          break;
        if (y + yScore > lScore)
          break;
        update(xScore, yScore);
      }
      loop(yScore, 0, lScore) {
        auto xScore = max(mnScore, yScore + 2);
        if (x + xScore > lScore)
          break;
        if (y + yScore > lScore)
          break;
        update(xScore, yScore);
      }
    };
    loop(nWin, 0, lMatch) {
      loop(nLose, 0, lMatch) {
        if (nWin + nLose > 4)
          break;
        if (nWin == 3 || nLose == 3)
          break;
        // cout << nWin << sp << nLose << endl;
        loop(x, 0, lScore) {
          loop(y, 0, lScore) {
            if (dp[x][y][nWin][nLose].fi == -1)
              continue;
            updateState(x, y, nWin, nLose);
          }
        }
      }
    }
  }

  auto trace(int n, int m, int u, int v) {
    vector<pair<int, int>> ret;
    while (true) {
      auto [x, y] = dp[n][m][u][v];
      if (x == 0 && y == 0)
        break;
      ret.push_back({x, y});
      int win = (x > y);
      n -= x;
      m -= y;
      u -= win;
      v -= (1 - win);
    }
    return ret;
  }
} pre;

class Solver {
  int n, m;

public:
  bool better(pair<int, int> cur, pair<int, int> nxt) {
    if (cur.fi == -1)
      return true;
    if ((cur.fi - cur.se) < (nxt.fi - nxt.se))
      return true;
    return cur.fi < nxt.fi;
  }

  void operator()() {
    cin >> n >> m;
    pair<int, int> curBest = {-1, -1};
    loop(nWin, 0, lMatch) {
      loop(nLose, 0, lMatch) {
        if (nWin != 3 && nLose != 3)
          continue;
        if (pre.dp[n][m][nWin][nLose].fi == -1)
          continue;
        if (better(curBest, {nWin, nLose})) {
          curBest = {nWin, nLose};
        }
      }
    }
    if (curBest.fi == -1) {
      cout << "Impossible" << endl;
      return;
    }
    cout << curBest.fi << ":" << curBest.se << endl;
    auto rec = pre.trace(n, m, curBest.fi, curBest.se);
    reverse(rec.begin(),rec.end());
    for (auto [u, v] : rec)
      cout << u << ":" << v << sp;
    cout << endl;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  pre();

  int T;
  cin >> T;
  while (T--) {
    Solver solve;
    solve();
  }
}