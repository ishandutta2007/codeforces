#include <bits/stdc++.h>

using namespace std;

const int N = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long k;
  cin >> k;
  string s;
  cin >> s;
  vector<int> a;
  int tr = 0;
  for (int i = 0; i < (int) s.length(); i++) {
    a.push_back((int) (s[i] - '0'));
    tr += a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    int x = 9 - a[i];
    if (tr < k) {
      tr += x;
      ans++;
    } else {
      break;
    }
  }
  cout << ans;
  return 0;
}