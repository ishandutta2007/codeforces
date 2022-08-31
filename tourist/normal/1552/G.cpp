/**
 *    author:  tourist
 *    created: 25.07.2021 17:56:01       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << "ACCEPTED" << '\n';
    return 0;
  }
  vector<int> first(n, -1);
  vector<long long> mask(k, 0);
  for (int i = 0; i < k; i++) {
    int foo;
    cin >> foo;
    while (foo--) {
      int j;
      cin >> j;
      --j;
      mask[i] |= (1LL << j);
      if (first[j] == -1) {
        first[j] = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (first[i] == -1) {
      cout << "REJECTED" << '\n';
      return 0;
    }
  }
  vector<long long> win(n + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = n - 1; j >= n - i; j--) {
      win[i] |= (1LL << j);
    }
  }
  vector<vector<long long>> aux(k);
  for (int i = 0; i < k; i++) {
    aux[i].push_back(0);
    for (int j = n - 1; j >= 0; j--) {
      if (mask[i] & (1LL << j)) {
        long long val = aux[i].back();
        val |= (1LL << j);
        aux[i].push_back(val);
      }
    }
  }
  vector<int> last(k, -1);
  vector<int> pred(n, -1);
  for (int i = 0; i < n; i++) {
    pred[i] = last[first[i]];
    last[first[i]] = i;
  }
  vector<int> a(n, -1);
  function<void(int, long long)> Dfs = [&](int v, long long m) {
    if (v == n) {
      long long cur = m;
      for (int i = 0; i < k; i++) {
        int cc = __builtin_popcountll(cur & mask[i]);
        cur &= ~mask[i];
        cur |= aux[i][cc];
      }
      int cc = __builtin_popcountll(cur);
      if (cur != win[cc]) {
        cout << "REJECTED" << '\n';
        exit(0);
      }
      return;
    }
    if (pred[v] == -1 || a[pred[v]] == 0) {
      a[v] = 0;
      Dfs(v + 1, m);
      a[v] = -1;
    }
    {
      a[v] = 1;
      Dfs(v + 1, m | (1LL << v));
      a[v] = -1;
    }
  };
  Dfs(0, 0);
  cout << "ACCEPTED" << '\n';
  return 0;
}