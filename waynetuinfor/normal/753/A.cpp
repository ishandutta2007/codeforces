#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

int main() {
  cin >> n;
  const int N = n;
  for (int i = 1; i <= N; ++i) {
    if (n < i) {
      int t = ans.back(); ans.pop_back();
      t += n; ans.push_back(t);
      break;
    }
    ans.push_back(i); n -= i;
  }
  cout << ans.size() << '\n';
  for (int j : ans) cout << j << ' ';
  return 0;
}