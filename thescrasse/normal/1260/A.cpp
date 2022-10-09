#include <bits/stdc++.h>
using namespace std;
long long N, a, b, i, j, k, res;

int main() {
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> a >> b;
    res = 0;
    while (b != 0) {
      k = b / a;
      b -= k;
      a--;
      res += (k * k);
    }
    if (i != N) {
      cout << res << endl;
    } else {
      cout << res;
    }
  }
  return 0;
}