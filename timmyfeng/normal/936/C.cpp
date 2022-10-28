#include <bits/stdc++.h>
using namespace std;

string sorted(string s) {
  sort(s.begin(), s.end());
  return s;
}

string reversed(string s) {
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s, t;
  cin >> n >> s >> t;

  if (sorted(s) != sorted(t)) {
    cout << -1 << "\n";
    exit(0);
  }

  int l = n / 2;
  int r = l - 1;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    char target = (i % 2 == 0) ? t[r + 1] : t[l - 1];

    int x = 1;
    while (s[n - x] != target) {
      ++x;
    }

    ans.push_back(x);
    ans.push_back(n - x - i);
    ans.push_back(i + 1);

    s = reversed(s.substr(0, i)) + target + reversed(s.substr(i, n - x - i)) + reversed(s.substr(n - x + 1));

    if (i % 2 == 0) {
      ++r;
    } else {
      --l;
    }
  }

  if (s != t) {
    ans.push_back(n);
  }

  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}