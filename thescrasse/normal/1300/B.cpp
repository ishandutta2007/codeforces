#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a[200010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    res = 0;
    cin >> n;
    for (i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    sort(a, a + 2 * n);
    cout << a[n] - a[n - 1] << endl;
  }

  return 0;
}