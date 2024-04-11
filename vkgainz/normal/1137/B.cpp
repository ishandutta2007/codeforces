#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T>
vector<int> kmp(const T &a) {
  int n = a.size();
  vector<int> fail(n);
  fail[0] = -1;
  for (int i = 1; i < n; ++i) {
    fail[i] = fail[i - 1];
    while (~fail[i] && a[fail[i] + 1] != a[i]) {
      fail[i] = fail[fail[i]];
    }
    if (a[fail[i] + 1] == a[i]) {
      ++fail[i];
    }
  }
  return fail;
}
 
int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  int zero = 0, one = 0;
  for (auto c : s) {
    if (c == '0') {
      ++zero;
    } else {
      ++one;
    }
  }
  vector<int> fail = kmp(t);
  int cur = 0;
  while (zero || one) {
    if (!zero) {
      cout << 1;
      --one;
    } else if (!one) {
      cout << 0;
      --zero;
    } else {
      cout << t[cur];
      if (t[cur] == '0') {
        --zero;
      } else {
        --one;
      }
      ++cur;
      if (cur == (int) t.size()) {
        cur = fail.back() + 1;
      }
    }
  }
  cout << "\n";
  return 0;
}