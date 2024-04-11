#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

pair <int, int> ev[N];

long long x[N], p[N];
long long st[N], pref[N];

int main() {
  int dist, b, n;
  scanf("%d %d %d", &dist, &b, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &ev[i].first, &ev[i].second);
  }
  ev[n++] = make_pair(0, 0);
  ev[n++] = make_pair(dist, 0);
  sort(ev, ev + n);
  for (int i = 0; i < n; i++) {
    x[i] = ev[i].first;
    p[i] = ev[i].second;
  }
  for (int i = 0; i < n - 1; i++) {
    if (x[i + 1] - x[i] > b) {
      cout << -1 << endl;
      return 0;
    }
  }
  long long ans = 0;
  pref[0] = 0;
  int e = 0;
  for (int i = 0; i < n - 1; i++) {
    long long need = x[i + 1] - x[i];
    while (e > 0 && p[i] <= p[st[e - 1]]) {
      e--;
    }
    st[e] = i;
    if (e >= 1) {
      pref[e] = pref[e - 1] + (x[st[e]] - x[st[e - 1]]) * p[st[e]];
    }
    e++;
    int low = 0, high = e - 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (x[st[mid]] <= x[i] - b) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    int pos = low;
    long long can = b - (x[i] - x[st[pos]]);
    if (can >= need) {
      ans += need * p[st[pos]];
      continue;
    }
    ans += can * p[st[pos]];
    need -= can;
    low = pos + 1, high = e - 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (x[st[mid]] - x[st[pos]] >= need) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    ans += pref[low - 1] - pref[pos];
    need -= x[st[low - 1]] - x[st[pos]];
    ans += p[st[low]] * need;
  }
  cout << ans << endl;
  return 0;
}