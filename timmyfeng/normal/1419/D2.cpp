#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

int ans[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (int i = 0, j = 1; i < n; ++i) {
    if (j >= n) {
      j = 0;
    }
    ans[j] = a[i];
    j += 2;
  }

  int cnt = 0;
  for (int i = 1; i < n - 1; ++i) {
    cnt += (ans[i - 1] > ans[i] && ans[i] < ans[i + 1]);
  }

  cout << cnt << "\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}