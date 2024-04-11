#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, cn, ps[110], res;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> s;
    res = 0;
    cn = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        ps[cn] = i;
        cn++;
      }
    }
    if (cn < 2) {
      cout << 0 << endl;
    } else {
      for (i = ps[0]; i <= ps[cn - 1]; i++) {
        if (s[i] == '0') {
          res++;
        }
      }
      cout << res << endl;
    }
  }

  return 0;
}