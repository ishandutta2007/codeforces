#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int where[N], maxi[N], prv[N], a[N];
bool mul[N];

void solve(int l, int r) {
  for ( ; l < r && a[l] == 1; ++l);
  for ( ; l < r && a[r] == 1; --r);

  int p = 1, m = 0;
  for (int i = l; i <= r; ++i) {
    if (a[i] > 1) {
      p = min(10 * N, p * a[i]);
      where[m++] = i;
    }
  }

  if (p >= 10 * N) {
    fill(mul + l + 1, mul + r + 1, true);
    return;
  }

  fill(maxi, maxi + m + 1, 0);
  fill(prv, prv + m + 1, 0);

  for (int i = 0; i < m; ++i) {
    p = 1;
    int g = (i == 0) ? 0 : where[i] - where[i - 1] - 1;
    for (int j = i; j < m; ++j) {
      p *= a[where[j]];
      if (maxi[i] + p + g > maxi[j + 1]) {
        maxi[j + 1] = maxi[i] + p + g;
        prv[j + 1] = i;
      }
    }
  }

  while (m > 0) {
    fill(mul + where[prv[m]] + 1, mul + where[m - 1] + 1, true);
    m = prv[m];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  string s;
  cin >> s;
  sort(s.begin(), s.end());

  if (s.size() == 1 || s == "+-") {
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        cout << s[0];
      }
      cout << a[i];
    }
    cout << "\n";
    exit(0);
  }

  if (s == "*-") {
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        cout << (a[i] == 0 ? "-" : "*");
      }
      cout << a[i];
    }
    cout << "\n";
    exit(0);
  }

  for (int i = 0, j = 0; i < n; i = j) {
    if (a[i] == 0) {
      ++j;
    } else {
      for ( ; j < n && a[j] > 0; ++j);
      solve(i, j - 1);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << (mul[i] ? "*" : "+");
    }
    cout << a[i];
  }
  cout << "\n";
}