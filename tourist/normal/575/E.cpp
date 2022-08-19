#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
const int N = 400010;

int x[N], y[N];
long long dist[N];
int km;

inline bool cmp(int i, int j) {
  int xi = x[i] - x[km];
  int yi = y[i] - y[km];
  int xj = x[j] - x[km];
  int yj = y[j] - y[km];
  long long vmul = xi * 1LL * yj - xj * 1LL * yi;
  if (vmul != 0) {
    return (vmul > 0);
  }
  return dist[i] < dist[j];
}

int mn[MAX + 10], mx[MAX + 10];
int id[N];
int nx[N], ny[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= MAX; i++) {
    mn[i] = MAX + 1;
    mx[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int px, py, pv;
    scanf("%d %d %d", &px, &py, &pv);
    for (int s = -pv; s <= pv; s++) {
      int from = py - pv + abs(s);
      int to = py + pv - abs(s);
      from = max(from, 0);
      to = min(to, MAX);
      int xx = px + s;
      if (0 <= xx && xx <= MAX) {
        mn[xx] = min(mn[xx], from);
        mx[xx] = max(mx[xx], to);
      }
    }
  }
  n = 0;
  for (int i = 0; i <= MAX; i++) {
    if (mx[i] != -1) {
      x[n] = i;
      y[n] = mn[i];
      n++;
      if (mn[i] < mx[i]) {
        x[n] = i;
        y[n] = mx[i];
        n++;
      }
    }
  }
  km = 0;
  for (int i = 1; i < n; i++) {
    if (y[i] < y[km] || (y[i] == y[km] && x[i] < x[km])) {
      km = i;
    }
  }
  for (int i = 0; i < n; i++) {
    dist[i] = (x[i] - x[km]) * 1LL * (x[i] - x[km]) + (y[i] - y[km]) * 1LL * (y[i] - y[km]);
    id[i] = i;
  }
  sort(id, id + n, cmp);
  for (int i = 0; i < n; i++) {
    nx[i] = x[id[i]];
    ny[i] = y[id[i]];
  }
  for (int i = 0; i < n; i++) {
    x[i] = nx[i];
    y[i] = ny[i];
  }
  int e = 1;
  for (int i = 1; i < n; i++) {
    while (e > 1) {
      long long a = y[e - 1] - y[e - 2];
      long long b = x[e - 2] - x[e - 1];
      long long c = -a * x[e - 1] - b * y[e - 1];
      long long z = a * x[i] + b * y[i] + c;
      if (z >= 0) {
        e--;
      } else {
        break;
      }
    }
    x[e] = x[i];
    y[e] = y[i];
    e++;
  }
  n = e;
  double ans = -1.0;
  int pos = -1;
  for (int i = 0; i < n; i++) {
    long long xa = x[i];
    long long ya = y[i];
    long long xb = x[(i + 1) % n];
    long long yb = y[(i + 1) % n];
    long long xc = x[(i + 2) % n];
    long long yc = y[(i + 2) % n];
    double a = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
    double b = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    double c = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    double area = 0.5 * abs((xa - xb) * (ya + yb) + (xb - xc) * (yb + yc) + (xc - xa) * (yc + ya));
    double rad = a * b * c / (4 * area);
    if (rad > ans) {
      ans = rad;
      pos = i;
    }
  }
  int i = pos;
  long long xa = x[i];
  long long ya = y[i];
  long long xb = x[(i + 1) % n];
  long long yb = y[(i + 1) % n];
  long long xc = x[(i + 2) % n];
  long long yc = y[(i + 2) % n];
  cout << xa << " " << ya << endl;
  cout << xb << " " << yb << endl;
  cout << xc << " " << yc << endl;
  return 0;
}