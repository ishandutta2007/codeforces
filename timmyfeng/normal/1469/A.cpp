#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    cout << (s.size() % 2 == 0 && s[0] != ')' && s.back() != '(' ? "YES" : "NO") << "\n";
  }
}