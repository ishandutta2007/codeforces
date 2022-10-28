#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

double maxi[N], mini[N], a[N], b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> maxi[i];
    maxi[i] += maxi[i - 1];
  }

  for (int i = 0; i < n; ++i) {
    cin >> mini[i];
  }

  for (int i = n - 1; i >= 0; --i) {
    mini[i] += mini[i + 1];
  }

  for (int i = 0; i <= n; ++i) {
    double x = mini[i] - maxi[i] - 1.0;
    a[i] = (-x + sqrt(max(0.0, x * x - 4 * maxi[i]))) / 2.0;
    b[i] = (-x - sqrt(max(0.0, x * x - 4 * maxi[i]))) / 2.0;
  }

  for (int i = 1; i <= n; ++i) {
    cout << a[i] - a[i - 1] << " ";
  }
  cout << "\n";

  for (int i = 1; i <= n; ++i) {
    cout << b[i] - b[i - 1] << " ";
  }
  cout << "\n";
}