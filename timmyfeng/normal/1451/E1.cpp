#include <bits/stdc++.h>
using namespace std;

int query(string s, int i, int j) {
  cout << s << " " << i << " " << j << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> ans(n + 1);

  int sum12 = query("XOR", 1, 2);
  int sum23 = query("XOR", 2, 3);
  int sum13 = sum12 ^ sum23;

  sum12 += 2 * query("AND", 1, 2);
  sum23 += 2 * query("AND", 2, 3);
  sum13 += 2 * query("AND", 1, 3);

  ans[1] = (sum12 - sum23 + sum13) / 2;
  ans[2] = (sum23 - sum13 + sum12) / 2;
  ans[3] = (sum13 - sum12 + sum23) / 2;

  for (int i = 1; i <= n; ++i) {
    if (i > 3) {
      ans[i] = query("XOR", 1, i) ^ ans[1];
    }
  }

  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}