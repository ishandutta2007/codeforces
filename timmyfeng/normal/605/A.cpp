#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int where[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    where[a - 1] = i;
  }

  int length = 1, ans = 1;
  for (int i = 1; i < n; ++i) {
    if (where[i] > where[i - 1]) {
      ++length;
    } else {
      length = 1;
    }
    ans = max(ans, length);
  }

  cout << n - ans << "\n";
}