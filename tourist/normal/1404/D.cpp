/**
 *    author:  tourist
 *    created: 06.09.2020 18:20:21       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "First" << endl;
    for (int i = 0; i < 2 * n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << i % n + 1;
    }
    cout << endl;
  } else {
    cout << "Second" << endl;
    vector<int> p(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<int> any(n, -1);
    vector<int> to(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      if (any[p[i]] == -1) {
        any[p[i]] = i;
      } else {
        int j = any[p[i]];
        to[i] = j;
        to[j] = i;
      }
    }
    vector<int> color(2 * n, 0);
    for (int i = 0; i < 2 * n; i++) {
      if (color[i] == 0) {
        int x = i;
        while (color[x] == 0) {
          color[x] = 1;
          color[to[x]] = -1;
          x = (to[x] + n) % (2 * n);
        }
      }
    }
    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
      if (color[i] == 1) {
        sum += i + 1;
        ++cnt;
      }
    }
    assert(sum % n == 0 && cnt == n);
    if (sum % (2 * n) != 0) {
      for (int i = 0; i < 2 * n; i++) {
        color[i] = -color[i];
      }
    }
    vector<int> res;
    for (int i = 0; i < 2 * n; i++) {
      if (color[i] == 1) {
        res.push_back(i + 1);
      }
    }
    for (int i = 0; i < (int) res.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << res[i];
    }
    cout << endl;
  }
  int foo;
  cin >> foo;
  return 0;
}