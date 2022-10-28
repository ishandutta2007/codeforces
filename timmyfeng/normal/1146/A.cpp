#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  cout << min((int) s.size(), count(s.begin(), s.end(), 'a') * 2 - 1) << "\n";
}