/**
 *  author: milos
 *  created: 04.01.2021 01:51:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  auto Add = [&](int x, int y) {
    g[x].push_back(y);
  };
  for (int rep = 0; rep < 2; rep++) {
    vector<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && a[st.back()] < a[i]) {
        Add(st.back(), i);
        st.pop_back();  
      }
      if (!st.empty())  {
        Add(st.back(), i);
        if (a[st.back()] == a[i]) {
          st.pop_back();
        }
      }
      st.push_back(i);
    }
    for (int i = 0; i < n; i++) {
      a[i] = -a[i];
    }
  }
  vector<int> dist(n, -1);
  vector<int> q(1, 0);
  dist[0] = 0;
  for (int i = 0; i < (int) q.size(); i++) {
    for (int j : g[q[i]]) {
      if (dist[j] == -1) {
        dist[j] = dist[q[i]] + 1;
        q.push_back(j);
      }         
    }
  }
  cout << dist[n - 1] << '\n';
  return 0;
}