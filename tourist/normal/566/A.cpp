#include <bits/stdc++.h>

using namespace std;

const int LEN = 1600010;
const int N = 400010;

char foo[LEN], s[LEN];
int start[N], finish[N], id[N];

bool cmp(int x, int y) {
  int px = start[x];
  int py = start[y];
  while (px < finish[x] && py < finish[y] && s[px] == s[py]) {
    px++;
    py++;
  }
  if (px == finish[x] && py == finish[y]) {
    return false;
  }
  if (px == finish[x]) {
    return true;
  }
  if (py == finish[y]) {
    return false;
  }
  return (s[px] < s[py]);
}

int lcp[N], sum1[N], sum2[N];
pair <int, int> ev[N];
int _pr[N], _ne[N];
vector <int> unmatched[N];
int match[N];

int main() {
  int n;
  scanf("%d", &n);
  int total = 0;
  for (int i = 0; i < 2 * n; i++) {
    scanf("%s", foo);
    start[i] = total;
    for (int j = 0; foo[j]; j++) {
      s[total++] = foo[j];
    }
    finish[i] = total;
    id[i] = i;
  }
  sort(id, id + 2 * n, cmp);
  for (int i = 0; i < 2 * n - 1; i++) {
    lcp[i] = 0;
    int px = start[id[i]];
    int py = start[id[i + 1]];
    while (px < finish[id[i]] && py < finish[id[i + 1]] && s[px] == s[py]) {
      px++;
      py++;
      lcp[i]++;
    }
  }
  sum1[0] = sum2[0] = 0;
  for (int i = 0; i < 2 * n; i++) {
    sum1[i + 1] = sum1[i] + (id[i] < n);
    sum2[i + 1] = sum2[i] + (id[i] >= n);
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    ev[i] = make_pair(lcp[i], i);
  }
  int *pr = _pr + 1;
  int *ne = _ne + 1;
  for (int i = -1; i <= 2 * n; i++) {
    pr[i] = i - 1;
    ne[i] = i + 1;
  }
  for (int i = 0; i < 2 * n; i++) {
    unmatched[i].push_back(id[i]);
  }
  sort(ev, ev + 2 * n - 1);
  long long ans = 0;
  for (int it = 2 * n - 2; it >= 0; it--) {
    int pos = ev[it].second;
    int l1 = sum1[pos + 1] - sum1[pr[pos] + 1];
    int l2 = sum2[pos + 1] - sum2[pr[pos] + 1];
    int r1 = sum1[ne[pos] + 1] - sum1[pos + 1];
    int r2 = sum2[ne[pos] + 1] - sum2[pos + 1];
    if ((l1 > l2 && r2 > r1) || (l2 > l1 && r1 > r2)) {
      int cnt = min(abs(l1 - l2), abs(r2 - r1));
      ans += lcp[pos] * 1LL * cnt;
      for (int j = 0; j < cnt; j++) {
        int u = unmatched[pr[pos] + 1].back();
        int v = unmatched[pos + 1].back();
        if (u < n) {
          match[u] = v;
        } else {
          match[v] = u;
        }
        unmatched[pr[pos] + 1].pop_back();
        unmatched[pos + 1].pop_back();
      }
    }
    if (unmatched[pos + 1].size() > unmatched[pr[pos] + 1].size()) {
      swap(unmatched[pos + 1], unmatched[pr[pos] + 1]);
    }
    while (!unmatched[pos + 1].empty()) {
      unmatched[pr[pos] + 1].push_back(unmatched[pos + 1].back());
      unmatched[pos + 1].pop_back();
    }
    pr[ne[pos]] = pr[pos];
    ne[pr[pos]] = ne[pos];
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", i + 1, match[i] - n + 1);
  }
  return 0;
}