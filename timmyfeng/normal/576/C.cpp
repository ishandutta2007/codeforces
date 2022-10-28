#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
const int B = 1000;

array<int, 3> points[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points[i] = {x, y, i};
  }

  sort(points, points + n, [&](array<int, 3> a, array<int, 3> b) {
    if (a[0] / B == b[0] / B) {
      if (a[0] / B % 2 == 0) {
        return a[1] < b[1];
      } else {
        return a[1] > b[1];
      }
    }
    return a[0] < b[0];
  });

  for (int i = 0; i < n; ++i) {
    cout << points[i][2] + 1 << " ";
  }
  cout << "\n";
}