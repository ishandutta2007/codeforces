/**
 *    author:  tourist
 *    created: 18.09.2017 16:09:28       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(7, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 7; j++) {
      a[j] += (s[j] - '0');
    }
  }
  int mx = 0;
  for (int j : a) mx = max(mx, j);
  printf("%d\n", mx);
  return 0;
}