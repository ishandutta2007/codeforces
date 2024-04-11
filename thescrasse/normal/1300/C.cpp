#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a[100010], m, dn, check1;
vector<vector<long long>> bits1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (i = 0; i < 60; i++) {
    bits1.push_back({});
  }

  for (i = 0; i < n; i++) {
    m = a[i];
    k = 50;
    while (m != 0) {
      if (m % 2 == 1) {
        bits1[k].push_back(i);
      }
      m = m / 2;
      k--;
    }
  }
  check1 = 0;
  for (i = 0; i <= 50; i++) {
    //cout << i << ' ' << bits1[i].size() << endl;
    if (bits1[i].size() == 1) {
      dn = a[bits1[i][0]];
      check1 = 1;
      break;
    }
  }

  if (check1 == 0) {
    for (i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
  } else {
    cout << dn << ' ';
    for (i = 0; i < n; i++) {
      if (a[i] != dn) {
        cout << a[i] << ' ';
      }
    }
  }

  return 0;
}