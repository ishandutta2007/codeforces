#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  set<int> values;

  int n;
  cin >> n;

  while (n--) {
    int a;
    cin >> a;
    values.insert(a);
  }

  int d = *(--values.end()) - *values.begin();
  if (values.size() == 1) {
    cout << 0 << "\n";
  } else if (values.size() == 2) {
    cout << (d % 2 == 0 ? d / 2 : d) << "\n";
  } else if (values.size() == 3) {
    if (d % 2 == 0 && values.count(*values.begin() + d / 2) > 0) {
      cout << d / 2 << "\n";
    } else {
      cout << -1 << "\n";
    }
  } else {
    cout << -1 << "\n";
  }
}