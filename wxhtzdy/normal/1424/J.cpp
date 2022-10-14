/**
 *    author:  milos
 *    created: 01.10.2021 07:21:27       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = (int) 1e6 + 5;
  vector<int> cnt(MAX);
  for (int i = 2; i < MAX; i++) {
    if (cnt[i] != 0) continue;
    for (int j = i + i; j < MAX; j += i) {
      cnt[j]++;
    }
  }
  vector<int> pref(MAX);
  for (int i = 1; i < MAX; i++) {
    pref[i] = pref[i - 1] + (cnt[i] == 0 ? 1 : 0); 
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << pref[n] - pref[sqrt(n)] + 1 << '\n';
  }
  return 0;
}