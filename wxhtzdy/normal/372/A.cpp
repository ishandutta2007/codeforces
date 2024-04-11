#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& i : a) cin >> i;

  sort(a.begin(), a.end());

  auto Can = [&](int x) {
    int j = 0;
    for (int i = x; i < n; i++) {
      if (j < x && a[i] >= a[j] * 2) {
        j++;
      }
    }
    return j == x;
  };

  int bot = 1, top = n, ans = 0;
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      ans = mid;
      bot = mid + 1;
    } else {
      top = mid - 1;
    }
  }

  cout << n - ans << '\n';
}