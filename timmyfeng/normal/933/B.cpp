#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long p, k;
  cin >> p >> k;
  k = -k;

  vector<int> ans;
  while (p != 0) {
    int rem = p % k;
    if (rem < 0) {
      rem -= k;
    }

    ans.push_back(rem);
    p -= rem;
    p /= k;
  }

  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}