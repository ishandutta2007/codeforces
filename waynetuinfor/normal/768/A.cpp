#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, a;
map<int, int> m;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a, ++m[a];
  if (m.size() == 1) return cout << "0\n", 0;
  cout << n - m.begin()->second - m.rbegin()->second << '\n';
  return 0;
}