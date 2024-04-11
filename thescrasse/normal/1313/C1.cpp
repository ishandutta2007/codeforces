#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, a[500010], l[500010], r[500010];
stack<pair<long long, long long>> nse;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i + 1];
  }

  k = 1;
  while (k <= n) {
    //cout << k << endl;
    if (nse.empty()) {
      nse.push({a[k], k});
      l[k] = k * a[k];
      k++;
      if (k == n + 1) {
        break;
      }
    }
    if (nse.top().first < a[k]) {
      j = nse.top().second;
      nse.push({a[k], k});
      //cout << "j k = " << j << ' ' << k << endl;
      l[k] = l[j] + (k - j) * a[k];
      k++;
      if (k == n + 1) {
        break;
      }
    } else {
      nse.pop();
    }
  }

  while (!nse.empty()) {
    nse.pop();
  }

  k = n;
  while (k >= 1) {
    //cout << k << endl;
    if (nse.empty()) {
      nse.push({a[k], k});
      r[k] = (n + 1 - k) * a[k];
      k--;
      if (k == 0) {
        break;
      }
    }
    if (nse.top().first < a[k]) {
      j = nse.top().second;
      nse.push({a[k], k});
      r[k] = r[j] + (j - k) * a[k];
      k--;
      if (k == 0) {
        break;
      }
    } else {
      nse.pop();
    }
  }

  res = 0;
  k = 0;
  /*for (i = 1; i <= n; i++) {
    cout << l[i] << ' ' << r[i] << endl;
  }*/
  for (i = 1; i <= n; i++) {
    if (l[i] + r[i] - a[i] > res) {
      k = i;
      res = l[i] + r[i] - a[i];
    }
  }

  for (i = k - 1; i >= 1; i--) {
    a[i] = min(a[i], a[i + 1]);
  }
  for (i = k + 1; i <= n; i++) {
    a[i] = min(a[i], a[i - 1]);
  }
  for (i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}