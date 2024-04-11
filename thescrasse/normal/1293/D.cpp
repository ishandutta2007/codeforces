#include <bits/stdc++.h>
using namespace std;
long long i, j, k, x0, y00, ax, bx, ay, by, xs, ys, t, x, y, n3, p1016, initialtime[200], recdist[200], res, it;
vector<pair<long long, long long>> nodes;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //ifstream cin("input.txt");
 // ofstream cout("output.txt");
  res = 0;
  cin >> x0 >> y00 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  x = x0;
  y = y00;
  n3 = 3;
  p1016 = pow(10, 16);
  nodes.push_back({x, y});
  while (x * ax + bx < n3 * p1016 && y * ay + by < n3 * p1016) {
    x = x * ax + bx;
    y = y * ay + by;
    nodes.push_back({x, y});
  }
  for (i = 0; i < nodes.size(); i++) {
    initialtime[i] = t - (abs(nodes[i].first - xs) + abs(nodes[i].second - ys));
  }
  for (i = 0; i < nodes.size() - 1; i++) {
    recdist[i] = abs(nodes[i].first - nodes[i + 1].first) + abs(nodes[i].second - nodes[i + 1].second);
  }
  for (i = 0; i < nodes.size(); i++) {
    if (initialtime[i] >= 0) {
      k = 1;
      it = initialtime[i];
      j = i - 1;
      while (j != -1) {
        // cout << initialtime[i] << endl;
        initialtime[i] -= recdist[j];
        j--;
        if (initialtime[i] >= 0) {
          k++;
          // cout << "k = " << k << endl;
        } else {
          break;
        }
      }
      initialtime[i] = 2 * initialtime[i] - it;
      if (initialtime[i] >= 0) {
        j = i;
        while (j != nodes.size() - 1) {
          // cout << initialtime[i] << endl;
          initialtime[i] -= recdist[j];
          j++;
          if (initialtime[i] >= 0) {
            k++;
            // cout << "k = " << k << endl;
          } else {
            break;
          }
        }
      }
      res = max(k, res);
    }
  }
  cout << res;

  return 0;
}