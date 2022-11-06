#include <iostream>
#include <string>
using namespace std;

string s;
int n, k, g;
bool v[105], dpa[105];
bool dp(int);

int main() {
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < n; ++i) if (s[i] == 'G') g = i;
  cout << (dp(g) ? "YES" : "NO") << '\n';
}

bool dp(int p) {
  if (s[p] == 'T') return true;
  if (s[p] == '#') return false;
  if (v[p]) return dpa[p];
  v[p] = true;
  if (p + k < n) dpa[p] |= dp(p + k);
  if (p - k >= 0) dpa[p] |= dp(p - k);
  return dpa[p];
}