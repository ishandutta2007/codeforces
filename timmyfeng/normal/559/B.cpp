#include <bits/stdc++.h>
using namespace std;

string process(string a) {
  if (a.size() % 2 == 1) {
    return a;
  } else {
    string l = a.substr(0, a.size() / 2);
    string r = a.substr(a.size() / 2);
    l = process(l), r = process(r);
    if (l > r) {
      swap(l, r);
    }
    return l + r;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  cout << (process(a) == process(b) ? "YES" : "NO") << "\n";
}