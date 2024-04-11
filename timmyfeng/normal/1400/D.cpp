#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int cnt_l[N];
int cnt_r[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
      fill(cnt_l, cnt_l + n, 0);
      for (int j = i + 1; j < n; ++j) {
        ++cnt_r[a[j]];
      }

      int64_t sum = 0;
      for (int j = i + 1; j < n; ++j) {
        --cnt_r[a[j]];
        sum -= cnt_l[a[j]];
        if (a[j] == a[i]) {
          ans += sum;
        }
        ++cnt_l[a[j]];
        sum += cnt_r[a[j]];
      }
    }

    cout << ans << "\n";
  }
}