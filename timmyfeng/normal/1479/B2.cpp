#include <bits/stdc++.h>
using namespace std;
 
const int N = 100000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  set<int> prv = {0};
  int ans = 1;

  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      continue;
    }

    if (prv.count(a[i]) > 0) {
      prv.clear();
    } else {
      ++ans;
    }
    prv.insert(a[i - 1]);
  }

  cout << ans << "\n";
}