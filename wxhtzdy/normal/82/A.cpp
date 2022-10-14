#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int nxt = 5, kk = 2;
  string s[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  if (n < 6) {
    cout << s[n - 1] << '\n';
    return 0;
  }
  while (nxt < n) {
    nxt += kk * 5;
    kk *= 2;
  }
  int diff = n - (nxt - (kk / 2) * 5) - 1;
  if (nxt == n) cout << s[4] << '\n';
  else cout << s[diff / (kk / 2)] << '\n';
  return 0;
}