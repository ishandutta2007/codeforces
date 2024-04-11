#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int sum = 0;
  for (char c : s) {
    sum += c - '0';
  }

  if (sum == 0) {
    cout << "YES\n";
    exit(0);
  }

  for (int i = 1; i < sum; ++i) {
    int ptr = 0;
    int cur = i;
    while (ptr < n && cur == i) {
      cur = 0;
      while (ptr < n && cur + s[ptr] - '0' <= i) {
        cur += s[ptr] - '0';
        ++ptr;
      }
    }
    if (cur == i) {
      cout << "YES\n";
      exit(0);
    }
  }
  cout << "NO\n";
}