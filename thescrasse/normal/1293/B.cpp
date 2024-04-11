#include <bits/stdc++.h>
using namespace std;
long long N, i, j, k, n, s, x;
long double res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 // ifstream cin("input.txt");
 // ofstream cout("output.txt");
  cin >> N;
  res = 0;
  for (i = 1; i <= N; i++) {
    res += (long double)1 / i;
  }
  cout << setprecision(10);
  cout << res;
  return 0;
}