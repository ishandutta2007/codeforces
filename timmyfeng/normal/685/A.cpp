#include <bits/stdc++.h>
using namespace std;

int ln, lm, n, m;
bool used[7];
int watch[7];

int solve(int i) {
  if (i == ln + lm) {
    int vn = 0, vm = 0;
    for (int i = 0; i < ln; ++i) {
      vn = 7 * vn + watch[i];
    }
    for (int i = ln; i < ln + lm; ++i) {
      vm = 7 * vm + watch[i];
    }
    return vn < n && vm < m;
  }

  int ans = 0;
  for (int j = 0; j < 7; ++j) {
    if (!used[j]) {
      used[j] = true;
      watch[i] = j;
      ans += solve(i + 1);
      used[j] = false;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  ln = lm = 1;
  for (int i = 7; i < n && ln < 7; i *= 7, ++ln);
  for (int i = 7; i < m && lm < 7; i *= 7, ++lm);

  cout << solve(0) << "\n";
}