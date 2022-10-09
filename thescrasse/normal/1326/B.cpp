#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a[200010], b[200010], x[200010];
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
      cin >> b[i];
  }
  x[0] = 0;
  a[0] = b[0];
  for (i = 1; i < n; i++) {
      x[i] = max(x[i - 1], a[i - 1]);
      a[i] = x[i] + b[i];
  }

  for (i = 0; i < n; i++) {
      cout << a[i] << ' ';
  }

  return 0;
}