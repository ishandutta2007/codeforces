#include <bits/stdc++.h>
using namespace std;

const int N = 200;

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
    }

    set<int> diff;
    for (int i = 0; i < n; ++i) {
      diff.insert((a[i] - a[(i + 1) % n] + n) % n);
    }

    if ((diff.count(1) == 1 || diff.count(n - 1) == 1) && diff.size() == 1u) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}