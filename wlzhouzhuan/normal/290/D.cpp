#include <bits/stdc++.h>
using namespace std;
string s;
int x; 
int main() {
  cin >> s >> x;
  for (auto &v: s) {
    if (v >= 'A' && v <= 'Z') v -= 'A' - 'a';
    if (v < 'a' + x) v += 'A' - 'a';
  }
  cout << s << '\n';
}