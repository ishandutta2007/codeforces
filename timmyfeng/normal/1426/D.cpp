#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<long long, int> prv;
  prv[0] = -1;

  long long sum = 0;
  int last = -2;
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum += a;
    if (prv.count(sum) && prv[sum] >= last) {
      last = i - 1;
      ++ans;
    }
    prv[sum] = i;
  }

  cout << ans << "\n";
}