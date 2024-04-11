#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int ans1[N];
int ans2[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }

  bool ok = false;
  for (int i = 0; i < n; ++i) {
    ok |= (a[i] > 1 && a[i + 1] > 1);
  }
  if (!ok) {
    cout << "perfect\n";
    exit(0);
  }
  cout << "ambiguous\n";

  int pre = 0;
  int cur = 1;
  bool big = false;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      ans1[cur] = pre;
      ans2[cur] = pre + (big && (j > 0));
      ++cur;
    }
    pre = cur - a[i];
    big = (a[i] > 1);
  }

  for (int i = 1; i < cur; ++i) {
    cout << ans1[i] << " ";
  }
  cout << "\n";

  for (int i = 1; i < cur; ++i) {
    cout << ans2[i] << " ";
  }
  cout << "\n";
}