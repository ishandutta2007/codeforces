#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
  cin >> s >> t;
  if (s == t) return cout << "-1\n", 0;
  cout << max((int)s.length(), (int)t.length()) << '\n';
  return 0;
}