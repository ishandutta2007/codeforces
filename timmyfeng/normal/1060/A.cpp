#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  cout << min(n / 11, (int) count(s.begin(), s.end(), '8')) << "\n";
}