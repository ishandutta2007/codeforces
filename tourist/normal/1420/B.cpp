/**
 *    author:  tourist
 *    created: 24.09.2020 20:17:56       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // 0 & 0 == 0   ==   0 == 0 ^ 0
  // 0 & 1 == 0   <    1 == 0 ^ 1
  // 1 & 0 == 0   <    1 == 1 ^ 0
  // 1 & 1 == 1   >    0 == 1 & 1

  //     A = 010011110
  //     B = 111001111
  
  // A & B = 010001110
  // A ^ B = 101010001

  //     A = 110011110
  //     B = 111001111
  
  // A & B = 110001110
  // A ^ B = 001010001

  // (A & B) >= (A ^ B) if and only if A's and B's highest bits match

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> cnt(32, 0);
    for (int i = 0; i < n; i++) {
//      int bit = __builtin_clz(a[i]);
      int bit = 0;
      while ((1 << (bit + 1)) <= a[i]) {
        ++bit;
      }
      // (1 << bit) is the highest power of 2 <= a[i]
      cnt[bit] += 1;
    }
    long long ans = 0;
    for (int bit = 0; bit < 32; bit++) {
      ans += (long long) cnt[bit] * (cnt[bit] - 1) / 2;
    }
    cout << ans << '\n';
  }
  
  return 0;
}