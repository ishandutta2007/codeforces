#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  set<int> prv;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    prv.erase(a);
    prv.insert(i);
  }

  cout << prv.size() << "\n";
}