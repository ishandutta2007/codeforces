#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int mn = 10;
    for (int win = 0; win < 2; win++) {
      int cnt[2] = {0, 0};
      int moves[2] = {5, 5};
      for (int i = 0; i < 10; i++) {
        moves[i % 2]--;
        if (s[i] == '1') cnt[i % 2]++;
        if (s[i] == '?' && i % 2 == win) cnt[i % 2]++;
        if (cnt[win] > cnt[win ^ 1] + moves[win ^ 1]) mn = min(mn, i + 1);
      }
    }
    cout << mn << "\n";
  }
}