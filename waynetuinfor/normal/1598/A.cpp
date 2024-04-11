#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= s[0][i] == '0' || s[1][i] == '0';
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
}