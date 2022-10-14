#include <bits/stdc++.h>

using namespace std;

int Ask(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int x;
  cin >> x;
  return (r - l + 1) - x;
}

void run_case() {
  int n, t;
  cin >> n >> t;
  while (t--) {
    int k;
    cin >> k;
    int bot = 1, top = n, ans = n;
    while (bot <= top) {
      int mid = bot + top >> 1;
      if (Ask(1, mid) < k) {
        bot = mid + 1;
      } else {
        ans = mid;
        top = mid - 1;
      }
    }
    cout << "! " << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int test = 1;
  while (test-- > 0)
    run_case();
    return 0;
}