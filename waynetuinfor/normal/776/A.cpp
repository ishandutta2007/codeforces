#include <bits/stdc++.h>
using namespace std;

string a, b;
int n;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> a >> b;
  cin >> n;
  cout << a << ' ' << b << '\n';
  for (int i = 0; i < n; ++i) {
    string s, t;
    cin >> s >> t;
    if (s == a) {
      a = t;
    } else {
      b = t;
    }
    cout << a << ' ' << b << '\n';
  }
  return 0;
}