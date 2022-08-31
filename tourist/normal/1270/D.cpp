/**
 *    author:  tourist
 *    created: 29.12.2019 17:19:45       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto Get = [&](const vector<int>& b) {
    cout << "?";
    for (int x : b) {
      cout << " " << x + 1;
    }
    cout << endl;
    int x, y;
    cin >> x >> y;
    return make_pair(y, x);
  };
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    a[i] = i;
  }
  vector<pair<int, int>> r;
  r.push_back(Get(a));
  for (int i = k - 1; i >= 0; i--) {
    ++a[i];
    r.push_back(Get(a));
  }
  sort(r.begin(), r.end());
  for (int i = 0; i < (int) r.size() - 1; i++) {
    if (r[i] != r[i + 1]) {
      cout << "! " << (int) r.size() - i - 1 << endl;
      return 0;
    }
  }
  cout << "NO SAD" << '\n';
  assert(false);
  return 0;
}