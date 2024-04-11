#include <bits/stdc++.h>

using namespace std;

long long mabs(long long x) {
  return (x < 0 ? -x : x);
}

const int N = 1234567;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    total += mabs(a[i]);
  }
  long long ans = 0;
  long long z = 1;
  map <long long, int> mp;
  while (mabs(z) <= total) {
    mp.clear();
    mp[0]++;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
      ans += mp[s - z];
      mp[s]++;
    }
    z *= k;
    if (z == 1 && mabs(k) == 1) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}