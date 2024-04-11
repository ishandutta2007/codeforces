#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

long long cost[N], new_cost[N];
int x[N], y[N];

int main() {
  int n, start;
  scanf("%d %d", &n, &start);
  vector <int> pos;
  pos.push_back(start);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
    pos.push_back(x[i]);
    pos.push_back(y[i]);
  }
  sort(pos.begin(), pos.end());
  int cnt = pos.size();
  for (int i = 0; i < cnt; i++) {
    cost[i] = abs(pos[i] - start);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < cnt; j++) {
      new_cost[j] = cost[j] + (pos[j] < x[i] ? (x[i] - pos[j]) : 0) + (pos[j] > y[i] ? (pos[j] - y[i]) : 0);
    }
    for (int j = 0; j + 1 < cnt; j++) {
      if (pos[j] < x[i] && new_cost[j] < new_cost[j + 1]) {
        new_cost[j + 1] = new_cost[j];
      }
    }
    for (int j = cnt - 1; j >= 0; j--) {
      if (pos[j] > y[i] && new_cost[j] < new_cost[j - 1]) {
        new_cost[j - 1] = new_cost[j];
      }
    }
    for (int j = 0; j < cnt; j++) {
      cost[j] = new_cost[j];
    }
  }
  long long ans = cost[0];
  for (int j = 1; j < cnt; j++) {
    ans = min(ans, cost[j]);
  }
  cout << ans << endl;
  return 0;
}