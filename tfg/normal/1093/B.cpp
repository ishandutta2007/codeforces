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
    std::string s, t;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    t = s;
    std::reverse(t.begin(), t.end());
    if(s == t) {
      std::cout << "-1\n";
    } else {
      std::cout << s << '\n';
    }
  }
  return 0;
}