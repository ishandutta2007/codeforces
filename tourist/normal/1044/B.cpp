/**
 *    author:  tourist
 *    created: 04.11.2018 21:45:54       
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
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> my, his;
    vector<int> in_my(n, 0);
    vector<int> in_his(n, 0);
    int foo;
    cin >> foo;
    for (int i = 0; i < foo; i++) {
      int x;
      cin >> x;
      x--;
      my.push_back(x);
      in_my[x] = 1;
    }
    cin >> foo;
    for (int i = 0; i < foo; i++) {
      int x;
      cin >> x;
      x--;
      his.push_back(x);
      in_his[x] = 1;
    }
    cout << "B " << his[0] + 1 << endl;
    int start;
    cin >> start;
    start--;
    vector<int> que(1, start);
    vector<int> was(n, 0);
    was[start] = 1;
    int ask = -1;
    if (in_my[start]) {
      ask = start;
    }
    for (int b = 0; b < (int) que.size(); b++) {
      for (int j : g[que[b]]) {
        if (!was[j]) {
          que.push_back(j);
          was[j] = 1;
          if (in_my[j] && ask == -1) {
            ask = j;
          }
        }
      }
      if (ask != -1) {
        break;
      }
    }
    assert(ask != -1);
    cout << "A " << ask + 1 << endl;
    int finish;
    cin >> finish;
    finish--;
    int ans = (in_his[finish] ? ask + 1 : -1);
    cout << "C " << ans << endl;
  }
  return 0;
}