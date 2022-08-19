/**
 *    author:  tourist
 *    created: 18.09.2017 16:22:43       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N], pref_last[N], suff_last[N];
long long pref_sum[N], suff_sum[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  {
    long long sum = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
      int now = max(last + 1, a[i]);
      sum += now - a[i];
      last = now;
      pref_sum[i] = sum;
      pref_last[i] = last;
    }
  }
  {
    long long sum = 0;
    int last = 0;
    for (int i = n - 1; i >= 0; i--) {
      int now = max(last + 1, a[i]);
      sum += now - a[i];
      last = now;
      suff_sum[i] = sum;
      suff_last[i] = last;
    }
  }
  long long ans = (long long) 4e18;
  for (int i = 0; i < n; i++) {
    long long cur = pref_sum[i] + suff_sum[i];
    cur -= (pref_last[i] - a[i]);
    cur -= (suff_last[i] - a[i]);
    cur += max(pref_last[i], suff_last[i]) - a[i];
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}