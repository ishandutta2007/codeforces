/**
 *    author:  milos
 *    created: 26.01.2021 22:42:09       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  cout << s / n + (s % n > 0 ? 1 : 0) << '\n';
  return 0;
}