#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int val[N];

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;
  long long sum = 0;
  for (int i = 0; i < (1 << n); ++i) {
    cin >> val[i];
    sum += val[i];
  }

  cout << 1.0 * sum / (1 << n) << "\n";
  for (int i = 0; i < r; ++i) {
    int a, b;
    cin >> a >> b;
    sum -= val[a];
    val[a] = b;
    sum += val[a];
    cout << 1.0 * sum / (1 << n) << "\n";
  }
}