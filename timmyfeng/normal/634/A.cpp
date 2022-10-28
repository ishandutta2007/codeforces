#include <bits/stdc++.h>
using namespace std;

vector<int> read(int n) {
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x != 0) {
      a.push_back(x);
    }
  }
  rotate(a.begin(), find(a.begin(), a.end(), 1), a.end());
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << (read(n) == read(n) ? "YES" : "NO") << "\n";
}