/**
 *    author:  tourist
 *    created: 24.09.2017 17:35:18       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set<string> s;
  for (int i = 0; i < n; i++) {
    string w;
    cin >> w;
    if (s.find(w) != s.end()) puts("YES"); else puts("NO");
    s.insert(w);
  }
  return 0;
}