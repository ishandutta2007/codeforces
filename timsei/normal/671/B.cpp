#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

int n, A[N], k, now, Sum, B[N], S[N];

int calcR(void) {
  int it = k;
  for(int i = n; i >= 1; -- i) {
    int gap = (A[i] - A[i - 1]);
    if(gap * (n - i + 1) > it) {
      int now = A[i], num = n - i + 1;
      now -= it / num;
      return now;
    }
    it -= gap * (n - i + 1);
  }
  assert(0);
  return -1;
}

int calcL(void) {
  int it = k;
  for(int i = 1; i <= n; ++ i) {
    int gap = (A[i + 1] - A[i]);
    if(gap * i > it) {
      int now = A[i], num = i;
      now += it / num;
      return now;
    }
    it -= gap * i;
  }
  assert(0);
  return -1;
}

main(void) {
  cin >> n >> k;
  for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]), Sum += A[i];
  sort(A + 1, A + n + 1);
  for(int i = 1; i <= n; ++ i) {
    B[i] = Sum / n;
    if(i <= Sum % n) ++ B[i];
  }
  sort(B + 1, B + n + 1);
  for(int i = 1; i <= n; ++ i) now += abs(A[i] - B[i]);
  now /= 2;
  if(now <= k) {
    printf("%d\n", (Sum % n) ? 1 : 0);
    return 0;
  }
  for(int i = 1; i <= n; ++ i) S[i] = S[i - 1] + abs(A[i] - B[i]);
  int R = calcR(), L = calcL();
  cout << R - L << endl;
}