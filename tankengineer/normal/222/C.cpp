#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, cntc[10000005], a[100005], b[100005], t1, cnta[10000005], cntb[10000005], top, p[3205];
bool flag[3200];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 2; i < 3200; ++i) {
    if (!flag[i]) {
      p[++top] = i;
      for (int j = i * i; j < 3200; j += i) {
        flag[j] = true;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    t1 = a[i];
    for (int j = 1; j <= top; ++j) {
      while (t1 % p[j] == 0) {
        ++cnta[j];
        t1 = t1 / p[j];
      }
      if (t1 == 1) break;
    }
    if (t1 != 1) {
      ++cnta[t1];
    }
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    t1 = b[i];
    for (int j = 1; j <= top; ++j) {
      while (t1 % p[j] == 0) {
        ++cntb[j];
        t1 = t1 / p[j];
      }
      if (t1 == 1) break;
    }
    if (t1 != 1) {
      ++cntb[t1];
    }    
  }
  for (int i = 1; i <= 10000000; ++i) {
    cntc[i] = min(cnta[i], cntb[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= top; ++j) {
      while (cntc[j] && a[i] % p[j] == 0) {
        --cntc[j];
        a[i] /= p[j];
      }
      if (a[i] == 1) break;
    }
    int t2 = a[i];
    for (int j = 1; j <= top; ++j) {
      while (t2 % p[j] == 0) t2 /= p[j];
    }
    while (t2 > 3200 && cntc[t2]) {
      --cntc[t2];
      a[i] /= t2;
      t2 = 1;
    }
  }
  for (int i = 1; i <= 10000000; ++i) {
    cntc[i] = min(cnta[i], cntb[i]);
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= top; ++j) {
      while (cntc[j] && b[i] % p[j] == 0) {
        --cntc[j];
        b[i] /= p[j];
      }
      if (b[i] == 1) break;
    }
    int t2 = b[i];
    for (int j = 1; j <= top; ++j) {
      while (t2 % p[j] == 0) t2 /= p[j];
    }
    while (t2 > 3200 && cntc[t2]) {
      --cntc[t2];
      b[i] /= t2;
      t2 = 1;
    }
  }
  printf("%d %d\n", n, m);
  for (int i = 1; i < n; ++i) printf("%d ", a[i]);
  printf("%d\n", a[n]);
  for (int j = 1; j < m; ++j) printf("%d ", b[j]);
  printf("%d\n", b[m]);
  return 0;
}