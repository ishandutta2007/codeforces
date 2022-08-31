/**
 *    author:  tourist
 *    created: 02.09.2018 17:40:58       
**/
#include <bits/stdc++.h>

using namespace std;

void err() {
  cout << "No" << '\n';
  exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    cin >> order[i];
    order[i]--;
  }
  if (order[0] != 0) {
    err();
  }
  vector<int> was(n, 0);
  was[0] = 1;
  int b = 0;
  int e = 1;
  while (b < e) {
    int i = order[b];
    set<int> put;
    for (int j : g[i]) {
      if (!was[j]) {
        put.insert(j);
      }
    }
    set<int> get;
    for (int id = e; id < e + (int) put.size(); id++) {
      get.insert(order[id]);
    }
    if (put != get) {
      err();
    }
    for (int x : put) {
      was[x] = 1;
    }
    e += (int) put.size();
    b++;
  }
  if (e != n) {
    err();
  }
  cout << "Yes" << '\n';
  return 0;
}