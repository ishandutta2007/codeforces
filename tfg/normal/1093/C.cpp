#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for(int i = 0; i < n / 2; i++) {
    long long v;
    std::cin >> v;
    if(i == 0) {
      a[0] = 0;
      a[n-1] = v;
      continue;
    }
    a[i] = a[i-1];
    a[n-i-1] = v - a[i];
    long long d = std::max(0LL, a[n-i-1] - a[n-i]);
    a[i] += d;
    a[n-i-1] -= d;
    d = std::max(0LL, -a[n-i-1]);
    a[i] -= d;
    a[n-i-1] += d;
  }
  for(int i = 0; i < n; i++) {
    std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}