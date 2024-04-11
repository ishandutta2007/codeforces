/**
 *  author: milos
 *  created: 27.09.2020 13:13:38
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
    vector<int> a(2 * n);
    vector<int> v1, v2;
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) {
        v1.push_back(i + 1);
      } else {
        v2.push_back(i + 1);
      }
    } 
    int id1 = 0, id2 = 0;
    for (int i = 0; i < n - 1; i++) {
      if (id1 < (int) v1.size() - 1) {
        cout << v1[id1] << " " << v1[id1 + 1] << '\n';
        id1 += 2;
      } else {
        cout << v2[id2] << " " << v2[id2 + 1] << '\n';
        id2 += 2;
      }
    }
  }
  return 0;
}