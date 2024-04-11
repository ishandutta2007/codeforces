#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a[40010], b[40010], m, k1, c1, c2, s;
vector<long long> dv;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  s = 0;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }

  for (i = 1; i <= sqrt(k); i++) {
    if (k % i == 0) {
      dv.push_back(i);
      if (i * i != k) {
        dv.push_back(k / i);
        s++;
      }
      s++;
    }
  }

  sort(dv.begin(), dv.end());

  /*for (i = 0; i < s; i++) {
    cout << dv[i] << ' ';
  }
  cout << endl;*/

  res = 0;

  for (i = 0; i < s; i++) {
    if (n >= dv[i] && m >= dv[s - i - 1]) {
      //cout << i << endl;
      c1 = 0;
      c2 = 0;
      k1 = 0;
      for (j = 0; j < n; j++) {
        //cout << j << endl;
        if (a[j] == 1) {
          k1++;
        } else {
          k1 = 0;
        }
        if (k1 >= dv[i]) {
          c1++;
        }
      }
      k1 = 0;
      for (j = 0; j < m; j++) {
        if (b[j] == 1) {
          k1++;
        } else {
          k1 = 0;
        }
        if (k1 >= dv[s - i - 1]) {
          c2++;
        }
      }
      //cout << i << ' ' << c1 << ' ' << c2 << endl;
      res = res + c1 * c2;
    }
  }

  cout << res;

  return 0;
}