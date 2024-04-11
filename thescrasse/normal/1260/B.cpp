#include <bits/stdc++.h>
using namespace std;
long long N, a, b, i, j, k, res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> a >> b;
    if (a == 0 && b == 0) {
      cout << "YES\n";
    } else if (a == 0 || b == 0) {
      cout << "NO\n";
    } else {
      if ((a + b) % 3 == 0 && !(a > 2 * b || b > 2 * a)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}