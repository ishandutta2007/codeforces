#include <bits/stdc++.h>
using namespace std;

const int N = 16;

int turns[1 << N][N * N][2];

int cost[N][2];
char color[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> color[i] >> cost[i][0] >> cost[i][1];
  }

  queue<array<int, 3>> que;
  que.push({0, 0, 0});
  int ans = INT_MAX;

  while (!que.empty()) {
    auto [mask, x, excess] = que.front();
    que.pop();

    int cur = turns[mask][x][excess];
    if (mask == (1 << n) - 1) {
      ans = min(ans, cur);
      continue;
    }

    array<int, 2> freq{}, have{}, save{};

    save[excess ^ 1] = __builtin_popcount(mask) - cur;
    have[excess] = x + cur - __builtin_popcount(mask);
    save[excess] = x;

    for (int i = 0; i < n; ++i) {
      if ((mask & (1 << i)) > 0) {
        ++freq[color[i] == 'B'];
        have[excess] -= cost[i][excess];
        save[excess ^ 1] += cost[i][excess ^ 1];
      }
    }

    for (int i = 0; i < n; ++i) {
      if ((mask & (1 << i)) == 0) {
        array<int, 3> to = {mask ^ (1 << i)};
        array<int, 2> new_have = have;
        int nxt = turns[mask][x][excess] + 1;

        for (int j = 0; j < 2; ++j) {
          new_have[j] -= max(0, cost[i][j] - freq[j]);
          if (new_have[j] < 0) {
            nxt += -new_have[j];
            new_have[j ^ 1] += -new_have[j];
            new_have[j] = 0;
          }
        }

        to[2] = new_have[0] == 0;
        to[1] = save[to[2]] + min(freq[to[2]], cost[i][to[2]]);

        int &t = turns[to[0]][to[1]][to[2]];
        if (t == 0) {
          que.push(to);
          t = nxt;
        } else {
          t = min(t, nxt);
        }
      }
    }
  }

  cout << ans << "\n";
}