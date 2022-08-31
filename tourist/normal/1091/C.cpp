/**
 *    author:  tourist
 *    created: 30.12.2018 17:38:25       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> all;
  auto test = [&](int g) {
    int k = n / g;
    int first = 1;
    int last = first + (k - 1) * g;
    all.push_back((long long) (first + last) * k / 2);
  };
  for (int g = 1; g * g <= n; g++) {
    if (n % g == 0) {
      test(g);
      test(n / g);
    }
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for (int i = 0; i < (int) all.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << all[i];
  }
  cout << "\n";
  return 0;
}