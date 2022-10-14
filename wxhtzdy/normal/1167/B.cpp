#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> niz;
  niz.push_back(4);
  niz.push_back(8);
  niz.push_back(15);
  niz.push_back(16);
  niz.push_back(23);
  niz.push_back(42);
  vector<int> a(4);
  for (int i = 0; i < 4; i++) {
    cout << "? " << i + 1 << " " << i + 2 << endl;
    cin >> a[i];
  }
  auto Valid = [&](vector<int> b) {
    for (int i = 0; i < 4; i++) {
      if (b[i] * b[i + 1] != a[i]) {
        return false;
      }
    }
    return true;
  };
  do {
    if (Valid(niz)) {
      cout << "! ";
      for (int i : niz) {
        cout << i << " ";
      }
      cout << endl;
    }
  } while (next_permutation(niz.begin(), niz.end()));
  return 0;
}