#include <bits/stdc++.h>
using namespace std;

string s;
int apr[26];
vector<int> v;

int main() {
  cin >> s;
  s = " " + s;
  fill(apr, apr + 26, INT_MAX);
  for (int i = 1; i < s.length(); ++i) {
    apr[s[i] - 'a'] = min(apr[s[i] - 'a'], i);
    v.push_back(s[i] - 'a');
  }
  sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
  if (v[0] > 0) return cout << "NO\n", 0;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] != v[i - 1] + 1) return cout << "NO\n", 0;
    if (apr[v[i - 1]] > apr[v[i]]) return cout << "NO\n", 0;
  }
  cout << "YES\n";
  return 0;
}