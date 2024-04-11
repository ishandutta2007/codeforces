// 1181C
// numero sottomatrici che formano una bandiera
// idee: hashing

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
using namespace std;

int i, i1, j, k, t, n, m, res, check1, a, b, s, mat[1010][1010];
char x;
vector<pair<int, int>> lst;
array<int, 5> v;
map<array<int, 5>, pair<int, int>> h;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m;
  for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
          cin >> x;
          mat[i][j] = (int)x;
      }
  }

  res = 0;

  for (j = 0; j < m; j++) {
      k = 1;
      lst.clear();
      for (i = 0; i < 3; i++) {
          lst.push_back({-1, -1});
      }
      for (i = 0; i < n; i++) {
          if (k > 1) {
              lst.pop_back();
          }
          lst.push_back({k, mat[i][j]});
          s = lst.size();
          if (lst[s - 1].first == lst[s - 2].first && lst[s - 1].first <= lst[s - 3].first) {
              v = {lst[s - 1].second, lst[s - 2].second, lst[s - 3].second, i, k};
              if (h[v].second == j - 1) {
                  res += ++h[v].first;
              } else {
                  h[v].first = 1;
                  res++;
              }
              h[v].second = j;
          }
          if (i != n - 1) {
              if (mat[i + 1][j] == mat[i][j]) {
                  k++;
              } else {
                  k = 1;
              }
          }
      }
  }

  cout << res;

  return 0;
}