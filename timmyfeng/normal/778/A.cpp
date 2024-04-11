#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

bool contains[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  int lo = 0;
  int hi = n;

  while (lo < hi) {
    int k = (lo + hi + 1) / 2;

    fill(contains, contains + n, false);
    for (int i = k; i < n; ++i) {
      contains[a[i]] = true;
    }

    int j = 0;
    for (int i = 0; i < n && j < m; ++i) {
      if (contains[i] && s[i] == t[j]) {
        ++j;
      }
    }

    if (j == m) {
      lo = k;
    } else {
      hi = k - 1;
    }
  }

  cout << lo << "\n";
}