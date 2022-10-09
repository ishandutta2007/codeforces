#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a, b, check1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> a >> b;
    if (a % b == 0) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }

  return 0;
}