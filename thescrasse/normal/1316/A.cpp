#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a, m, b;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> n >> m;
    a = 0;
    for (i = 0; i < n; i++) {
      cin >> b;
      a += b;
    }
    cout << min(a, m) << endl;
  }

  return 0;
}