#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int a, b, n, x, y, v;
double Min;

int main() {
  cin >> a >> b >> n;
  Min = 1e9;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> v;
    double t = sqrt((a - x) * (a - x) + (b - y) * (b - y)) / (double)v;
    Min = min(Min, t);
  }
  cout << fixed << setprecision(20) << Min << '\n';
  return 0;
}