#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, t, A[N], x, ans[N], Rev[N], now;

int Q(int l, int r) {
  cout << "? " <<  l <<" " << r << endl;
  fflush(stdout);
  cin >> x;
  return x;
}

void rev(int l, int r) {
  for(int i = l; i <= r; ++ i) {
    if(ans[i] != -1) ans[i] = 1 - ans[i];
    Rev[i] ^= 1;
  }
}

int solve(int l, int r, bool who) {
  int L = 0;
  if(!who) L = n - l + 1; else L = r;
  while (1) {
    now = Q(l, r);
    bool mask = abs(now - t) & 1;
    if (mask == (n - l + 1) % 2) mask = 0;
    else mask = 1;
    if(!mask) rev(l, n); else rev(1, r);
    if(mask == who) {
      int ans =  (now - t + L) >> 1;
      return ans;
    }
    else t = now;
  }
  assert(2132);
  return 0;
}

int main() {
  cin >> n >> t;
  for(int i = 1; i <= n; ++ i) ans[i] = -1;
  if(n == 1) {
    cout << "! " << t << endl;
    return 0;
  }
  if(n & 1) {
    int res = solve(2, n, 0);
    ans[1] = now - res;
    t = now;
    for(int i = 1; i < n; ++ i) {
      int res = solve(i, i + 1, 1);
      int Sum = 0;
      for(int j = 1; j <= i; ++ j) Sum += ans[j];
      ans[i + 1] = res - Sum;
      t = now;
    }
  }
  else {
    for(int i = 1; i <= n; ++ i) {
      int res = solve(i, i, 1);
      int Sum = 0;
      for(int j = 1; j < i; ++ j) Sum += ans[j];
      ans[i] = res - Sum;
      t = now;
    }
  }
  cout << "! ";
  for(int i = 1; i <= n; ++ i)
    if(Rev[i]) printf("%d", 1 - ans[i]);
    else printf("%d", ans[i]);
}