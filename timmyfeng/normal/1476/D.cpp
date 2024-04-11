#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 1;

bool dir[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
      dir[i] = (i % 2 == 1) ^ (s[i] == 'L');
    }

    fill(ans, ans + n + 1, 1);

    for (int i = 0, j = 0; i < n; i = j) {
      for ( ; j < n && dir[i] == dir[j]; ++j);
      for (int k = i; k <= j; ++k) {
        if (k % 2 == dir[i]) {
          ans[k] += j - i;
        }
      }
    }

    for (int i = 0; i <= n; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}