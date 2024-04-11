/**
 *    author:  tourist
 *    created: 16.09.2017 22:13:02       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const long long inf = (long long) 1e18;

long long ma[N], ml[N], mr[N];
int a[N];
long long s[N], f[N];

void modify(int q, long long v) {
  ma[q] = max(ma[q], v);
  int x = q;
  while (x < N) {
    ml[x] = max(ml[x], v);
    x |= (x + 1);
  }
  x = q;
  while (x >= 0) {
    mr[x] = max(mr[x], v);
    x = (x & (x + 1)) - 1;
  }
}

long long get(int ll, int rr) {
  long long v = -inf;
  int x = ll;
  while ((x | (x + 1)) <= rr) {
    v = max(v, mr[x]);
    x |= (x + 1);
  }
  v = max(v, ma[x]);
  x = rr;
  while ((x & (x + 1)) - 1 >= ll) {
    v = max(v, ml[x]);
    x = (x & (x + 1)) - 1;
  }
  return v;
}

int main() {
  int n;
  long long c;  
  cin >> n >> c;
  for (int i = 0; i < 2 * n - 1; i++) {
    scanf("%d", a + i);
  }
  s[0] = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    s[i + 1] = s[i] + a[i];
  }
  for (int i = 0; i < N; i++) {
    ma[i] = ml[i] = mr[i] = -inf;
  }
  f[0] = 0;
  modify(0, 0);
  for (int i = 1; i <= n; i++) {
    int low = 0, high = i;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (s[2 * i - 1] - s[2 * mid] < c) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    f[i] = -inf;
    if (low > 0) {
      f[i] = max(f[i], c + f[low - 1]);
    }
    if (low < i) {
      f[i] = max(f[i], s[2 * i - 1] + get(low, i - 1));
    }
    modify(i, f[i] - s[2 * i]);
  }
  cout << f[n] << endl;
  return 0;
}