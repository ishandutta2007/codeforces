#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, x, y;
long long ans;

int calc(int x) {
  if(!x) x += m;
  return (n / m) + (n % m >= x);
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; ++ i) {
    for(int j = 0; j < m; ++ j) {
      if((i * i + j * j) % m == 0) {
	ans += 1LL * calc(i) * calc(j);
      }
    }
  }
  cout << ans << endl;
}