#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, k;
  cin >> n >> k;                        
  vector<pair<int, int>> pos(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      --x;
      pos[x] = make_pair(i, j);
    }
  }
  vector<string> res(n, string(n, ' '));
  const int inf = 1e9;
  tuple<int, int, int> cl = make_tuple(inf, -1, -1);
  tuple<int, int, int> cr = make_tuple(-inf, -1, -1);
  tuple<int, int, int> rl = make_tuple(inf, -1, -1);
  tuple<int, int, int> rr = make_tuple(-inf, -1, -1);
  for (int v = n * n - 1; v >= 0; v--) {
    int i = pos[v].first;
    int j = pos[v].second;
    vector<pair<int, int>> cands;
    cands.emplace_back(get<1>(cl), get<2>(cl));    
    cands.emplace_back(get<1>(cr), get<2>(cr));    
    cands.emplace_back(get<1>(rl), get<2>(rl));    
    cands.emplace_back(get<1>(rr), get<2>(rr));
    bool ok = true;   
    for (auto c : cands) {
      int x = c.first;
      int y = c.second;
      if (x == -1) {
        continue;
      }
      int d = abs(i - x) + abs(j - y);
      ok &= (d <= k);
    }
    //cout << i << " " << j << " " << ok << endl;
    if (ok) {
      res[i][j] = 'M';
      cl = min(cl, make_tuple(i - j, i, j));
      cr = max(cr, make_tuple(i - j, i, j));
      rl = min(rl, make_tuple(i + j, i, j));
      rr = max(rr, make_tuple(i + j, i, j));
    } else {
      res[i][j] = 'G';
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << '\n';
  }                                                              
  return 0;
}