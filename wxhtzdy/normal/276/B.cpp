#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (char c : s) {
    cnt[c - 'a']++;
  }
  int sum = 0;
  for (int i = 0; i < 26; i++) {
    sum += cnt[i] % 2;
  }
  if (sum == 0 || sum % 2 == 1) {
    cout << "First";
  } else {
    cout << "Second";
  }
  return 0;
}