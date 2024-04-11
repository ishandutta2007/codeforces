#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < 26; ++i) {
    int len = 0;
    while (len * (len + 1) / 2 <= n) {
      ++len;
    }
    n -= len * (len - 1) / 2;
    cout << string(len, 'a' + i);
  }
}