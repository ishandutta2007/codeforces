#include <bits/stdc++.h>
using namespace std;

const int N = 2002;

int pre[N];
int suf[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + (a[i] == 1);
  }

  for (int i = n; i > 0; --i) {
    suf[i] = suf[i + 1] + (a[i] == 2);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int two = 0;
    int one = 0;
    for (int j = i; j <= n; ++j) {
      if (a[j] == 2) {
        ++two;
      } else {
        one = max(one, two) + 1;
      }
      ans = max(ans, pre[i - 1] + max(one, two) + suf[j + 1]);
    }
  }
  cout << ans << "\n";
}