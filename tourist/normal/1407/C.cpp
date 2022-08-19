/**
 *    author:  tourist
 *    created: 09.09.2020 21:34:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [&](int x, int y) {
    cout << "? " << x + 1 << " " << y + 1 << endl;
    int z;
    cin >> z;
    return z;
  };
  vector<int> p(n);
  int i = 0;
  for (int j = 1; j < n; j++) {
    int pi_mod_pj = Ask(i, j);
    int pj_mod_pi = Ask(j, i);
    if (pi_mod_pj > pj_mod_pi) {
      // pi < pj
      p[i] = pi_mod_pj;
      i = j;
    } else {
      // pi > pj
      p[j] = pj_mod_pi;
    }
  }
  p[i] = n;
  cout << "!";
  for (int i = 0; i < n; i++) {
    cout << " " << p[i];
  }
  cout << endl;
  return 0;
}