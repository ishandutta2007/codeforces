#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long)1e10;
const long long N = 400010;

long long fenw[N];
long long esz;

void modify(long long x, long long v) {
  while (x <= esz) {
    if (v < fenw[x]) fenw[x] = v;
    x = (x | (x - 1)) + 1;
  }
}

long long find_min(long long x) {
  long long v = inf;
  while (x > 0) {
    if (fenw[x] < v) v = fenw[x];
    x &= x - 1;
  }
  return v;
}

long long x[N], d[N];
long long st[N];
long long l[N], r[N];
long long pos[N];

int main() {
  int n;
  scanf("%d", &n);
  for (long long i = 0; i <= n + 1; i++) {
    int foo;
    scanf("%d", &foo);
    x[i] = foo;
  }
  for (long long i = 1; i <= n; i++) {
    int foo;
    scanf("%d", &foo);
    d[i] = 2LL * foo;
  }
  d[0] = d[n + 1] = x[n + 1] - x[0];
  r[0] = d[0];
  long long e = 1;
  st[0] = 0;
  for (long long i = 1; i <= n + 1; i++) {
    while (e >= 2 && d[st[e - 1]] < x[i] - x[st[e - 2]]) {
      e--;
    }
    r[i] = d[i] - (x[i] - x[st[e - 1]]);
    st[e++] = i;
  }
  if (e > 2) {
    printf("0.0\n");
    return 0;
  }
  l[n + 1] = d[n + 1];
  e = 1;
  st[0] = n + 1;
  for (long long i = n; i >= 0; i--) {
    while (e >= 2 && d[st[e - 1]] < x[st[e - 2]] - x[i]) {
      e--;
    }
    l[i] = d[i] - (x[st[e - 1]] - x[i]);
    st[e++] = i;
  }
  r[n + 1] = -inf;
  l[0] = -inf;
  vector < pair <long long, long long> > ev;
  for (long long i = 0; i <= n + 1; i++) {
    if (l[i] <= 0) {
      continue;
    }
    ev.push_back(make_pair(x[i] - l[i], i));
  }
  sort(ev.begin(), ev.end());
  esz = ev.size();
  for (long long q = 0; q < esz; q++) {
    pos[ev[q].second] = q + 1;
  }
  for (long long q = 1; q <= esz; q++) {
    fenw[q] = inf;
  }
  long long ans = inf;
  for (long long i = n + 1; i >= 0; i--) {
    if (r[i] > 0) {
      long long to = x[i] + r[i];
      long long to_pos = lower_bound(ev.begin(), ev.end(), make_pair(to + 1, -1LL)) - ev.begin();
      long long u = find_min(to_pos);
      if (u != inf) {
        if (u - x[i] < ans) {
          ans = u - x[i];
        }
      }
    }
    if (l[i] > 0) {
      modify(pos[i], x[i]);
    }
  }
  cout << (ans / 2) << "." << (ans % 2 * 5) << endl;
  return 0;
}