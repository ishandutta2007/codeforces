/**
 *    author:  tourist
 *    created: 07.10.2018 20:05:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  bx -= ax; by -= ay;
  cx -= ax; cy -= ay;
  auto signum = [&](int x) {
    return (x > 0 ? 1 : (x < 0 ? -1 : 0));
  };
  if (signum(bx) == signum(cx) && signum(by) == signum(cy)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}