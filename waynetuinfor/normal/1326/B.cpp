#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int p = 0;
  for (int i = 0; i < n; ++i) {
    int a = b[i] + p;
    cout << a << " ";
    p = max(p, a);
  }
  cout << "\n";
}