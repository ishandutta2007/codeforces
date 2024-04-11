#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, p, res, check1;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m >> p;
  check1 = 0;
  for (i = 0; i < n; i++) {
    cin >> k;
    if (k % p != 0 && check1 == 0) {
      res += i;
      check1 = 1;
    }
  }
  check1 = 0;
  for (i = 0; i < m; i++) {
    cin >> k;
    if (k % p != 0 && check1 == 0) {
      res += i;
      check1 = 1;
    }
  }

  cout << res;

  return 0;
}