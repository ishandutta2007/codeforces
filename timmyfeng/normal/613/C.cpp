#include <bits/stdc++.h>
using namespace std;

const int N = 26;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = accumulate(a, a + n, 0);

  if (n == 1) {
    cout << m << "\n";
    cout << string(m, 'a') << "\n";
    exit(0);
  }

  if (m % 2 == 0) {
    int g = 0;
    for (int i = 0; i < n; ++i) {
      g = __gcd(g, a[i]);
    }

    if (g % 2 == 1) {
      cout << 0 << "\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
          cout << (char) ('a' + i);
        }
      }
      cout << "\n";
      exit(0);
    }

    string s;
    for (int i = 0; i < n; ++i) {
      while (a[i] > 0) {
        s += 'a' + i;
        a[i] -= g;
      }
    }

    string t = s;
    reverse(t.begin(), t.end());

    string ans;
    while ((int) ans.size() < m) {
      ans += s + t;
    }

    cout << g << "\n";
    cout << ans << "\n";
  } else {
    int o = 0;
    for (int i = 0; i < n; ++i) {
      o += a[i] % 2;
    }

    if (o != 1) {
      cout << 0 << "\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
          cout << (char) ('a' + i);
        }
      }
      cout << "\n";
      exit(0);
    }

    int g = 0;
    for (int i = 0; i < n; ++i) {
      g = __gcd(g, (a[i] % 2 == 0) ? a[i] / 2 : a[i]);
    }

    string s;
    char c = '?';
    for (int i = 0; i < n; ++i) {
      while (a[i] >= 2 * g) {
        a[i] -= 2 * g;
        s += 'a' + i;
      }

      if (a[i] > 0) {
        c = 'a' + i;
      }
    }

    string t = s;
    reverse(t.begin(), t.end());

    string ans;
    while ((int) ans.size() < m) {
      ans += s + c + t;
    }

    cout << g << "\n";
    cout << ans << "\n";
  }
}