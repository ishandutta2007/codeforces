#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long)1e18;
const int N = 400010;

int last[N], pred[N], p[N], w[N];
long long even[N], odd[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    last[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d %d", p + i, w + i);
    p[i]--;
    if (p[i] >= 0) {
      pred[i] = last[p[i]];
      last[p[i]] = i;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    long long b0 = 0, b1 = -inf;
    int j = last[i];
    while (j >= 0) {
      long long nb0 = max(b0 + even[j], b1 + odd[j]);
      long long nb1 = max(b0 + odd[j], b1 + even[j]);
      b0 = nb0;
      b1 = nb1;
      j = pred[j];
    }
    even[i] = b0;
    odd[i] = b1;
    odd[i] = max(odd[i], even[i] + w[i]);
  }
  cout << max(even[0], odd[0]) << endl;
  return 0;
}