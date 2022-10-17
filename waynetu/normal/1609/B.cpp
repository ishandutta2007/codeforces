#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i + 2 < N; ++i) {
    if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
      cnt++;
    }
  }
  while (Q--) {
    int pos;
    string t;
    cin >> pos >> t;
    pos--;
    for (int i = max(0, pos - 2); i <= pos; ++i) {
      if (i + 2 < N) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
          --cnt;
        }
      }
    }
    s[pos] = t[0];
    for (int i = max(0, pos - 2); i <= pos; ++i) {
      if (i + 2 < N) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
          ++cnt;
        }
      }
    }
    cout << cnt << "\n";
  }
}