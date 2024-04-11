#include <bits/stdc++.h>

using namespace std;

int main() {
//  freopen("input.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  vector<long long> st(n + 1);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
    st[i + 1] = st[i] + t[i];
  }
  vector<int> cnt(n);
  vector<long long> rem(n);
  for (int i = 0; i < n; i++) {
    int l = i, r = n + 1;
    while (l < r - 1) {
      int m = (l + r) / 2;
      long long cst = st[m] - st[i];
      if (cst <= v[i]) {
        l = m;
      } else {
        r = m;
      }
    }
    ++cnt[i];
    if (l < n) --cnt[l];
    long long rema = v[i] - st[l] + st[i];
    if (l < n) {
      rem[l] += rema;
    }
  }
  long long bal = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
   bal += cnt[i]; 
   cout << bal * t[i] + rem[i] << " ";
  }
  cout << endl;
  return 0;
}