#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, hm[100], a[100010], a1, nsc[100], n1, res, check1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    check1 = 1;
    res = 0;
    for (i = 0; i < 100; i++) {
      hm[i] = 0;
      nsc[i] = 0;
    }
    cin >> n >> m;
    for (i = 0; i < m; i++) {
      cin >> a[i];
      a1 = a[i];
      k = -1;
      while (a1 != 0) {
        k++;
        a1 = a1 / 2;
      }
      hm[k]++;
      //cout << "k = " << k << endl;
    }
    //cout << endl;
    n1 = n;
    k = 0;
    while (n1 != 0) {
      nsc[k] = n1 % 2;
      //cout << "k = " << k << ", nsc[k] = " << nsc[k] << endl;
      k++;
      n1 = n1 / 2;
    }
    for (i = 0; i < 99; i++) {
      /*for (j = 0; j < 100; j++) {
        cout << hm[j] << ' ';
      }
      cout << endl;*/
      if (nsc[i] == 1) {
        if (hm[i] > 0) {
          hm[i]--;
          hm[i + 1] += (hm[i] / 2);
          hm[i] = hm[i] % 2;
        } else {
          check1 = 0;
          for (j = i; j < 100; j++) {
            hm[j]++;
            if (hm[j] > 1) {
              res = res + j - i;
              check1 = 1;
              hm[j] -= 2;
              hm[i]++;
              break;
            }
          }
          if (check1 == 0) {
            break;
          }
        }
      } else {
        hm[i + 1] += (hm[i] / 2);
        hm[i] = hm[i] % 2;
      }
    }
    if (check1 == 0) {
      cout << -1 << endl;
    } else {
      cout << res << endl;
    }
  }

  return 0;
}