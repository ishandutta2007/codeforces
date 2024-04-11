#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;
  int N = (n + 1) / 2;
  vector<int> a(N);
  for (int &el : a)
    cin >> el;
  int Ax;
  cin >> Ax;
  vector<int> m(N + 1, 0);
  int Pprefsm = 0;
  for (int i = 1; i < N + 1; ++i) {
    Pprefsm += Ax - a[i - 1];
    m[i] = min(m[i - 1], Pprefsm);
  }
  int Aprefsm = 0;
  for (int k = 1; k <= N; ++k)
    Aprefsm += a[k - 1];
  for (int k = N; k <= n; ++k) {
    if (Aprefsm + m[n - k] > 0)
      return cout << k, 0;
    Aprefsm += Ax;
  }
  cout << -1;
}