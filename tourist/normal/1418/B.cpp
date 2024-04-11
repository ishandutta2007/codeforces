/**
 *    author:  tourist
 *    created: 14.09.2020 20:09:38       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i];
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
      if (l[i] == 0) {
        b.push_back(a[i]);
      }
    }
    // a[1] a[2] a[3] a[4] ... a[n]
    // p[i] = a[1] + a[2] + ... + a[i]

    // i < j, a[i] < a[j]
    // what happens to p[] if we swap(a[i], a[j])?

    // p[1], p[2], ..., p[i-1] don't change
    // p[i]   increases by (a[j]-a[i])
    // p[i+1] increases by (a[j]-a[i])
    // ...
    // p[j-1] increases by (a[j]-a[i])
    // p[j], p[j+1], p[j+2], ..., p[n] don't change

    sort(b.rbegin(), b.rend());
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (l[i] == 0) {
        a[i] = b[j++];
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << '\n';
  }
  return 0;
}