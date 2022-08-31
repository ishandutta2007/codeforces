#include <bits/stdc++.h>

using namespace std;

struct Fraction {
  long long a;
  long long b;

  inline bool operator <(const Fraction &other) const {
    return a * other.b < b * other.a;
  }
};

const int N = 1234567;

int a[N];
long long s[N];
Fraction best;
int bi, bk;
int n;

inline Fraction get(int i, int k) {
  long long value = s[i + 1] - s[i - k];
  value += s[n] - s[n - k];
  Fraction cur = Fraction {value, 2LL * k + 1LL};
  cur.a -= a[i] * cur.b;
  if (best < cur) {
    best = cur;
    bi = i;
    bk = k;
//    cerr << best.a << "/" << best.b << " (" << i << " " << k << ")" << endl;
  }
  return cur;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  best = Fraction {0, 1};
  bi = 0;
  bk = 0;
  for (int i = 0; i < n; i++) {
    int high = min(i, n - i - 1);
    int low = 0;
    while (low + 3 < high) {
      int q1 = (2 * low + high) / 3;
      int q2 = (low + 2 * high) / 3;
      Fraction v1 = get(i, q1);
      Fraction v2 = get(i, q2);
      if (v1 < v2) {
        low = q1;
      } else {
        high = q2;
      }
    }
    for (int k = low; k <= high; k++) {
      get(i, k);
    }
  }
  vector <int> res;
  for (int i = bi - bk; i <= bi; i++) {
    res.push_back(a[i]);
  }
  for (int i = n - bk; i < n; i++) {
    res.push_back(a[i]);
  }
  int sz = res.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}