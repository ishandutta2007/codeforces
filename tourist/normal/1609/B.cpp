/**
 *    author:  tourist
 *    created: 28.11.2021 17:36:59       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  auto Is = [&](int i) {
    return (0 <= i && i + 2 < n && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
  };
  int cnt = 0;
  for (int i = 0; i < n - 2; i++) {
    cnt += Is(i);
  }
  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    --pos;
    cnt -= Is(pos - 2);
    cnt -= Is(pos - 1);
    cnt -= Is(pos);
    s[pos] = c;
    cnt += Is(pos - 2);
    cnt += Is(pos - 1);
    cnt += Is(pos);
    cout << cnt << '\n';
  }
  return 0;
}