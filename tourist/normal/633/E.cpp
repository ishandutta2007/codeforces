#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1.01e9;

const int N = 1234567;

int va[N], vl[N], vr[N];
int ca[N], cl[N], cr[N];
int n;

inline void modify_max(int q, int v) {
  va[q] = v;
  int x = q;
  while (x <= n) {
    if (v > vl[x]) {
      vl[x] = v;
    }
    x = (x | (x - 1)) + 1;
  }
  x = q;
  while (x > 0) {
    if (v > vr[x]) {
      vr[x] = v;
    }
    x &= x - 1;
  }
}

inline void modify_min(int q, int v) {
  ca[q] = v;
  int x = q;
  while (x <= n) {
    if (v < cl[x]) {
      cl[x] = v;
    }
    x = (x | (x - 1)) + 1;
  }
  x = q;
  while (x > 0) {
    if (v < cr[x]) {
      cr[x] = v;
    }
    x &= x - 1;
  }
}

inline int find_max(int ll, int rr) {
  int v = 0;
  int x = ll;
  while ((x | (x - 1)) + 1 <= rr) {
    if (vr[x] > v) {
      v = vr[x];
    }
    x = (x | (x - 1)) + 1;
  }
  if (va[x] > v) {
    v = va[x];
  }
  x = rr;
  while ((x & (x - 1)) >= ll) {
    if (vl[x] > v) {
      v = vl[x];
    }
    x &= x - 1;
  }
  return v;
}

inline int find_min(int ll, int rr) {
  int v = inf;
  int x = ll;
  while ((x | (x - 1)) + 1 <= rr) {
    if (cr[x] < v) {
      v = cr[x];
    }
    x = (x | (x - 1)) + 1;
  }
  if (ca[x] < v) {
    v = ca[x];
  }
  x = rr;
  while ((x & (x - 1)) >= ll) {
    if (cl[x] < v) {
      v = cl[x];
    }
    x &= x - 1;
  }
  return v;
}

int v[N], c[N];

inline void init(int nn) {
  n = nn;
  for (int i = 1; i <= n; i++) {
    va[i] = vl[i] = vr[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    modify_max(i, v[i]);
  }
  for (int i = 1; i <= n; i++) {
    ca[i] = cl[i] = cr[i] = inf;
  }
  for (int i = 1; i <= n; i++) {
    modify_min(i, c[i]);
  }
}

inline int test(int from, int to) {
  if (to < from || to > n) {
    return 0;
  }
  return min(find_max(from, to) * 100, find_min(from, to));
}

int res[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", v + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  init(n);
  for (int i = 1; i <= n; i++) {
    int low = i - 1, high = n + 1;
    while (low + 1 < high) {
      int mid = (low + high) >> 1;
      int x = find_max(i, mid) * 100;
      int y = find_min(i, mid);
      if (x < y) {
        low = mid;
      } else {
        high = mid;
      }
    }
    res[i - 1] = max(test(i, low), test(i, high));
  }
  sort(res, res + n);
  double ans = 0.0;
  double prob = 1.0;
  for (int i = 0; i <= n - k; i++) {
    if (prob < 1e-100) {
      break;
    }
    double q = k * 1.0 / (n - i);
    ans += prob * q * res[i];
    prob *= (1.0 - q);
  }
  printf("%.17f\n", ans);
  return 0;
}