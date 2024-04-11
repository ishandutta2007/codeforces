#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a) {
      cin >> i;
    }

    while (*min_element(a.begin(), a.end()) != 0) {
      int mx = *max_element(a.begin(), a.end());
      for (int& i : a) {
        i = mx - i;
      }
      --k;
    }

    int mx = *max_element(a.begin(), a.end());
    if (k % 2 == 1) {
      for (int& i : a) {
        i = mx - i;
      }
    }

    for (int i : a) {
      cout << i << " ";
    }
    cout << "\n";
  }
}