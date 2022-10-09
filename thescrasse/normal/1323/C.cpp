#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a, b, m, check1, c;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> s;
  k = 0;
  res = 0;
  c = -1;

  for (i = 0; i < n; i++) {
    if (s[i] == '(') {
      k++;
    } else {
      k--;
    }
    if (k < 0 && c == -1) {
      c = i;
    }
    if (k == 0 && c != -1) {
      res = res + i - c + 1;
      c = -1;
    }
  }

  if (k == 0) {
    cout << res;
  } else {
    cout << -1;
  }

  return 0;
}