#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i <= n; ++i) {
    int b;
    cin >> b;
    a[b - 1] = i;
  }

  int ptr = 0;
  for (int i = 0; i <= n; ++i) {
    while (ptr < n && a[n - 1 - ptr] <= i) {
      ++ptr;
    }
    cout << 1 + i - ptr << " ";
  }
  cout << "\n";
}