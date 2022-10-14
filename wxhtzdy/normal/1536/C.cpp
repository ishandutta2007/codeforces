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
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> cnt;
    int d = 0, k = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'D') d++;
      if (s[i] == 'K') k++;
      int g = __gcd(d, k);
      cnt[{d / g, k / g}]++;
      cout << cnt[{d / g, k / g}] << " ";
    }
    cout << '\n';
  }
}