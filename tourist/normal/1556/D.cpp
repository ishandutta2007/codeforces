/**
 *    author:  tourist
 *    created: 29.08.2021 17:48:11       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto And = [&](int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    long long x;
    cin >> x;
    return x;
  };
  auto Or = [&](int i, int j) {
    cout << "or " << i + 1 << " " << j + 1 << endl;
    long long x;
    cin >> x;
    return x;
  };
  auto Finish = [&](long long i) {
    cout << "finish " << i << endl;
  };
  vector<long long> a(n);
  {
    long long s01 = And(0, 1) + Or(0, 1);
    long long s02 = And(0, 2) + Or(0, 2);
    long long s12 = And(1, 2) + Or(1, 2);
    a[0] = (s01 + s02 - s12) / 2;
    a[1] = (s01 + s12 - s02) / 2;
    a[2] = (s02 + s12 - s01) / 2;
  }
  for (int i = 3; i < n; i++) {
    long long s0i = And(0, i) + Or(0, i);
    a[i] = s0i - a[0];
  }
  sort(a.begin(), a.end());
  Finish(a[k - 1]);
  return 0;
}