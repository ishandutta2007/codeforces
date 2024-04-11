#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 1e18;
const int infint = (int) 2e9;

const int N = 1234567;

int c[N];
int mask[N];

vector  <int> s[4];
int ptr[4];
int num[4];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (k > m) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    mask[i] = 0;
  }
  for (int t = 0; t < 2; t++) {
    int foo;
    scanf("%d", &foo);
    while (foo--) {
      int bar;
      scanf("%d", &bar);
      bar--;
      mask[bar] |= (1 << t);
    }
  }
  for (int i = 0; i < n; i++) {
    s[mask[i]].push_back(c[i]);
  }
  for (int t = 0; t < 4; t++) {
    sort(s[t].begin(), s[t].end());
  }
  ptr[3] = s[3].size();
  long long ans = inf;
  long long cur = 0;
  for (int z : s[3]) {
    cur += z;
  }
  for (int j = 0; j < 3; j++) {
    ptr[j] = 0;
  }
  for (int both = m; both >= 0; both--) {
    while (ptr[3] > both) {
      cur -= s[3][--ptr[3]];
    }
    while (ptr[0] + ptr[1] + ptr[2] < m - both) {
      int best = infint;
      int best_j = -1;
      for (int j = 0; j < 3; j++) {
        num[j] = (ptr[j] == (int) s[j].size() ? infint : s[j][ptr[j]]);
        if (num[j] < best) {
          best = num[j];
          best_j = j;
        }
      }
      if (best_j == -1) {
        break;
      }
      cur += s[best_j][ptr[best_j]++];
    }
    for (int t = 1; t <= 2; t++) {
      while (ptr[t] < k - both && ptr[t] != (int) s[t].size()) {
        if (ptr[0] == 0 && ptr[3 - t] <= k - both) {
          break;
        }
        if (ptr[3 - t] <= k - both || (ptr[0] != 0 && s[0][ptr[0] - 1] > s[3 - t][ptr[3 - t] - 1])) {
          cur -= s[0][--ptr[0]];
        } else {
          cur -= s[3 - t][--ptr[3 - t]];
        }
        cur += s[t][ptr[t]++];
      }
    }
    if (ptr[3] == both && ptr[1] + ptr[3] >= k && ptr[2] + ptr[3] >= k && ptr[0] + ptr[1] + ptr[2] + ptr[3] == m) {
      ans = min(ans, cur);
    }
  }
  cout << (ans == inf ? -1LL : ans) << endl;
  return 0;
}