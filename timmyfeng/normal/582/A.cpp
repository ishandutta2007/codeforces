#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  multiset<int> values;
  for (int i = 0; i < n * n; ++i) {
    int a;
    cin >> a;
    values.insert(a);
  }

  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int b = *prev(values.end());
    values.erase(values.find(b));
    for (auto j : a) {
      values.erase(values.find(__gcd(j, b)));
      values.erase(values.find(__gcd(j, b)));
    }
    a.push_back(b);
  }

  for (auto i : a) {
    cout << i << " ";
  }
  cout << "\n";
}