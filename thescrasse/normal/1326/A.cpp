#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a, b;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
      cin >> n;
      if (n == 1) {
          cout << -1 << endl;
      } else if (n % 3 == 1) {
          cout << 4;
          for (i = 0; i < n - 2; i++) {
              cout << 2;
          }
          cout << 3;
          cout << endl;
      } else {
          for (i = 0; i < n - 1; i++) {
              cout << 2;
          }
          cout << 3;
          cout << endl;
      }
  }

  return 0;
}