#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  map <int, int> xs;
  map <int, int> ys;
  map < pair <int, int>, int > zs;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    ans += (xs[x]++);
    ans += (ys[y]++);
    ans -= (zs[make_pair(x, y)]++);
  }
  cout << ans << endl;
  return 0;
}