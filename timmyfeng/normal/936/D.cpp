#include <bits/stdc++.h>
using namespace std;

const int N = 2'000'000 + 1;

int count_x[2];
int events[N];
int x[2][N];

bool swapped[N][2];
int charge[N][2];
int shot[N][2];

bool count(int i, int j) {
  return binary_search(x[i], x[i] + count_x[i], j);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> count_x[0] >> count_x[1] >> t;

  int m = 1;
  for (auto i : {0, 1}) {
    for (int j = 0; j < count_x[i]; ++j) {
      cin >> x[i][j];
      events[m] = x[i][j];
      events[m + 1] = x[i][j] + 1;
      m += 2;
    }
  }

  sort(events, events + m);
  m = unique(events, events + m) - events;

  charge[0][1] = INT_MIN;

  for (int i = 1; i < m; ++i) {
    for (auto j : {0, 1}) {
      int lane = min(charge[i - 1][j ^ 1], t);
      if (!count(j, events[i - 1]) && lane > charge[i - 1][j]) {
        charge[i][j] = lane + events[i] - events[i - 1];
        swapped[i][j] = true;
      } else {
        charge[i][j] = charge[i - 1][j] + events[i] - events[i - 1];
      }

      shot[i][j] = -1;
      if (count(j, events[i])) {
        if (charge[i][j] <= t) {
          charge[i][j] = INT_MIN;
        } else {
          charge[i][j] -= t;
          shot[i][j] = events[i] - charge[i][j];
        }
      }
    }
  }

  if (max(charge[m - 1][0], charge[m - 1][1]) < 0) {
    cout << "No\n";
    exit(0);
  }
  cout << "Yes\n";

  int j = (charge[m - 1][0] >= 0) ? 0 : 1;
  vector<array<int, 2>> shots;
  vector<int> swaps;

  for (int i = m - 1; i > 0; --i) {
    if (shot[i][j] != -1) {
      shots.push_back({shot[i][j], j + 1});
    }
    if (swapped[i][j]) {
      swaps.push_back(events[i - 1]);
      j ^= 1;
    }
  }

  cout << swaps.size() << "\n";
  while (!swaps.empty()) {
    cout << swaps.back() << " ";
    swaps.pop_back();
  }
  cout << "\n";

  cout << shots.size() << "\n";
  while (!shots.empty()) {
    auto [r, c] = shots.back();
    cout << r << " " << c << "\n";
    shots.pop_back();
  }
}