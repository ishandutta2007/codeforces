#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 1e5;
  vector<int> prime(N, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = i + i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }
  vector<int> p;
  for (int i = 0; i < N; i++) {
    if (prime[i]) {
      p.push_back(i);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int d;
    cin >> d;
    int x = *lower_bound(p.begin(), p.end(), d + 1);
    int y = *lower_bound(p.begin(), p.end(), x + d);
    cout << (long long) x * y << '\n';
  }
  return 0;
}