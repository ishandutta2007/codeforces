#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string s;
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h >> s;
    cout << count(s.begin(), s.end(), '0') * min(c0, c1 + h) +
        count(s.begin(), s.end(), '1') * min(c0 + h, c1) << "\n";
  }
}