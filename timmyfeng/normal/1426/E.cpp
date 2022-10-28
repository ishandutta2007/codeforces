#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int r1, s1, p1, r2, s2, p2;
  cin >> r1 >> s1 >> p1 >> r2 >> s2 >> p2;

  int max_w = min(r1, s2) + min(s1, p2) + min(p1, r2);
  int min_w = n - (min(s1 + r1, r2) + min(p1 + s1, s2) + min(r1 + p1, p2));

  cout << min_w << " " << max_w << "\n";
}