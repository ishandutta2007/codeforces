#include <bits/stdc++.h>
using namespace std;

int query(string s, int i, int j) {
  cout << s << " " << i + 1 << " " << j + 1 << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a = -1;
  int b = -1;

  map<int, int> prv;
  prv[0] = 0;

  vector<int> ans(n);
  for (int i = 1; i < n; ++i) {
    ans[i] = query("XOR", 0, i);
    if (prv.count(ans[i]) > 0) {
      a = prv[ans[i]];
      b = i;
    }
    prv[ans[i]] = i;
  }

  if (a != -1) {
    ans[0] = query("AND", a, b) ^ ans[a];
  } else {
    ans[0] = query("AND", 0, prv[1]) ^ (query("AND", 0, prv[2]) & 1);
  }

  for (int i = 1; i < n; ++i) {
    ans[i] ^= ans[0];
  }

  cout << "! ";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}