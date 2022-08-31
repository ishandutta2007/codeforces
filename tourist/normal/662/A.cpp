#include <bits/stdc++.h>

using namespace std;

void get(long long &v) {
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  v = 0;
  while ('0' <= ch && ch <= '9') {
    v = v * 10 + ch - '0';
    ch = getchar();
  }
}

const int N = 1000010;

long long A[N], B[N];

int main() {
  int n;
  scanf("%d", &n);
  long long u = 0;
  for (int i = 0; i < n; i++) {
    get(A[i]);
    get(B[i]);
    u ^= A[i];
    B[i] ^= A[i];
  }
  long long g = 0;
  int r = 0;
  for (int bit = 61; bit >= 0; bit--) {
    for (int i = r; i < n; i++) {
      if (B[i] & (1LL << bit)) {
        swap(B[i], B[r]);
        break;
      }
    }
    if (!(B[r] & (1LL << bit))) {
      continue;
    }
    if ((g & (1LL << bit)) != (u & (1LL << bit))) {
      g ^= B[r];
    }
    for (int i = r + 1; i < n; i++) {
      if (B[i] & (1LL << bit)) {
        B[i] ^= B[r];
      }
    }
    r++;
  }
  if (g != u) {
    puts("1/1");
    return 0;
  }
  cout << ((1LL << r) - 1) << "/" << (1LL << r) << endl;
  return 0;
}