/**
 *    author:  tourist
 *    created: 07.10.2018 20:59:18       
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> opt;
vector<int> pairs;
int ans;

void dfs(int i, int val) {
  if (i < 0) {
    ans += pairs[val];
    return;
  }
  dfs(i - 1, val);
  dfs(i - 1, val + opt[i]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, n, m;
  cin >> w >> n >> m;
  vector<int> cnt(1 << w);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector<int> p3(w + 1);
  p3[0] = 1;
  for (int i = 0; i < w; i++) {
    p3[i + 1] = p3[i] * 3;
  }
  vector<int> weight(1 << w);
  for (int i = 0; i < (1 << w); i++) {
    for (int j = 0; j < w; j++) {
      if (i & (1 << j)) {
        weight[i] += p3[j];
      }
    }
  }
  pairs.assign(p3[w], 0);
  for (int i = 0; i < (1 << w); i++) {
    for (int j = 0; j < (1 << w); j++) {
      pairs[weight[i] + weight[j]] += cnt[i] * cnt[j];
    }
  }
  for (int it = 0; it < m; it++) {
    string foo;
    cin >> foo;
    reverse(foo.begin(), foo.end());
    int val = 0;
    opt.clear();
    for (int i = 0; i < w; i++) {
      if (foo[i] == 'A') {
        opt.push_back(p3[i]);
      }
      if (foo[i] == 'X') {
        opt.push_back(2 * p3[i]);
      }
      if (foo[i] == 'a') {
        val += 2 * p3[i];
      }
      if (foo[i] == 'o') {
        val += p3[i];
        opt.push_back(p3[i]);
      }
      if (foo[i] == 'x') {
        val += p3[i];
      }
    }
    int sz = (int) opt.size();
    ans = 0;
    dfs(sz - 1, val);
    cout << ans << '\n';
  }
  return 0;
}