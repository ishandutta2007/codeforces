/**
 *    author:  tourist
 *    created: 18.06.2020 19:26:40       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int k = 1;
  while (k * k < n) {
    ++k;
  }
  vector<int> a;
  if (k * (k - 1) >= n) {
    a.assign(k - 1, k - 1);
    for (int i = 0; i < n - (k - 1) * (k - 1); i++) {
      a[i] += 1;
    }
  } else {
    a.assign(k, k);
    for (int i = 0; i < k * k - n; i++) {
      a[i] -= 1;
    }
  }
  int sz = (int) a.size();
  vector<int> pos(sz, 0);
  for (int i = 0; i < sz - 1; i++) {
    pos[i + 1] = pos[i] + a[i];
  }
  vector<int> state(n, 0);
  for (int x : pos) {
    state[x] = 2;
  }
  while (true) {
    vector<int> to;
    for (int i = 0; i < n; i++) {
      if (state[i] == 0) {
        to.push_back(i);
      }
    }
    if ((int) to.size() < k) {
      cout << 0 << endl;
      break;
    }
    cout << k;
    for (int i = 0; i < k; i++) {
      state[to[i]] = 1;
      cout << " " << to[i] + 1;
    }
    cout << endl;
    int x;
    cin >> x;
    --x;
    for (int i = 0; i < k; i++) {
      if (state[x] == 1) {
        state[x] = 0;
      }
      x = (x + 1) % n;
    }
  }
  return 0;
}