#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<bool> used(n + 1), stay(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] <= n && !used[a[i]]) {
      stay[i] = used[a[i]] = true;
    }
  }

  for (int i = 0, j = 1; i < n; ++i) {
    if (stay[i]) {
      cout << a[i] << " ";
    } else {
      while (used[j]) {
        ++j;
      }
      used[j] = true;
      cout << j << " ";
    }
  }
  cout << "\n";
}