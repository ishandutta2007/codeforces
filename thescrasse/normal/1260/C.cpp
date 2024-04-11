#include <bits/stdc++.h>
using namespace std;
long long N, a, b, c, a1, b1, i, j, k, res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> a >> b >> c;
    if (a > b) {
      k = b;
      b = a;
      a = k;
    }
    a1 = a;
    b1 = b;
    while (a1 != b1) {
      if (a1 > b1) {
        a1 = ((a1 - 1) % b1) + 1;
      } else {
        b1 = ((b1 - 1) % a1) + 1;
      }
    }
    a /= a1;
    b /= b1;
    if (b > a * (c - 1) + 1) {
      cout << "REBEL\n";
    } else {
      cout << "OBEY\n";
    }
  }
  return 0;
}