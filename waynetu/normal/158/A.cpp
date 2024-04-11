#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  int n, k;
  cin >> n >> k;
  int s[50];
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s, s + n, cmp);
  int th = s[k - 1];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] >= th && s[i] > 0) ans++;
    else break;
  }
  cout << ans << endl;
  return 0;
}