#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int q;
  std::cin >> q;
  while(q--) {
    int n;
    std::cin >> n;
    int ans = 1;
    while(!(ans * 2 <= n && n <= ans * 7)) {
      ans = 1 + rng() % 100;
    }
    std::cout << ans << '\n';
  }
  return 0;
}