#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

const int N = (int)1e5 + 10;
int a[N];
int a_copy[N];
vector<int> positions[2];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] %= 2;
  }
  bool has_solution = false;
  long long best_solution = 0;
  for (int t = 0; t < 2; t++) {
    positions[0].clear();
    positions[1].clear();
    for (int i = 0; i < n; i++) {
      positions[a[i]].push_back(i);
      a_copy[i] = a[i];
    }
    reverse(positions[0].begin(), positions[0].end());
    reverse(positions[1].begin(), positions[1].end());
    bool ok = true;
    long long cost = 0;
    for (int i = 0; i < n && ok; i++) {
      int target = (t + i) % 2;
      if (a_copy[i] == target) {
        positions[target].pop_back();
        continue;
      }
      if (positions[target].size() == 0) {
        ok = false;
        break;
      }
      int nearest = *prev(positions[target].end());
      swap(a_copy[nearest], a_copy[i]);
      cost += nearest - i;
      positions[target].pop_back();
    }
    if (!ok) {
      continue;
    }
    if (!has_solution) {
      has_solution = true;
      best_solution = cost;
    } else if (best_solution > cost) {
      best_solution = cost;
    }
  }
  printf("%lld\n", has_solution ? best_solution : -1);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif

  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}