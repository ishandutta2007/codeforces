#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

double dist(double a, double b, double c, double d) {
  return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

double x[N], y[N], save[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  long long ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;

  int n;
  cin >> n;

  double sum = 0.0;
  multiset<double> saves;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    sum += 2 * dist(tx, ty, x[i], y[i]);
    save[i] = dist(bx, by, x[i], y[i]) - dist(tx, ty, x[i], y[i]);
    saves.insert(save[i]);
  }

  double ans = sum + *saves.begin();
  saves.insert(0.0);

  for (int i = 0; i < n; ++i) {
    saves.erase(saves.find(save[i]));
    ans = min(ans, sum - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]) + *saves.begin());
    saves.insert(save[i]);
  }

  cout << ans << "\n";
}