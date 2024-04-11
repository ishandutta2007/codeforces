#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 1;

long long prefix[2][N];
int nxt[3][N];
int n;

vector<array<int, 2>> states[N][2];
int rects[N];

void update(array<int, 2> coord, int r) {
  auto [x, y] = coord;
  if (max(x, y) <= n) {
    rects[max(x, y)] = max(rects[max(x, y)], r);
    if (x < y) {
      states[x][0].push_back({y, r});
    } else if (y < x) {
      states[y][1].push_back({x, r});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> prefix[i][j];
      prefix[i][j] += prefix[i][j - 1];
    }
  }

  for (int k = 0; k < 3; ++k) {
    map<long long, int> prv;
    for (int i = n; i >= 0; --i) {
      long long sum = 0;
      for (int j = 0; j < 2; ++j) {
        if (((k + 1) & (1 << j)) > 0) {
          sum += prefix[j][i];
        }
      }
      nxt[k][i] = prv.count(sum) > 0 ? prv[sum] : n + 1;
      if (i < n) {
        nxt[k][i] = min(nxt[k][i], nxt[k][i + 1]);
      }
      prv[sum] = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      states[i][j].push_back({nxt[j ^ 1][i], rects[i] + 1});

      int extend = n + 1;
      for (auto [x, r] : states[i][j]) {
        if (r > rects[i]) {
          extend = min(extend, x);
        }
      }

      if (extend <= n) {
        array<int, 2> coord = {i + 1, i + 1};
        coord[j ^ 1] = extend;
        update(coord, rects[i] + 1);
        coord[j] = nxt[j][i];
        update(coord, rects[i] + 2);
      }
    }

    if (nxt[2][i] <= n) {
      rects[nxt[2][i]] = max(rects[nxt[2][i]], rects[i] + 1);
    }
    rects[i + 1] = max(rects[i + 1], rects[i]);
  }

  cout << rects[n] << "\n";
}