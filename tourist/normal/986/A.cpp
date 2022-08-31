/**
 *    author:  tourist
 *    created: 29.05.2018 18:34:56       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<vector<int>> dist(k, vector<int>(n, -1));
  for (int type = 0; type < k; type++) {
    vector<int> que;
    for (int i = 0; i < n; i++) {
      if (a[i] == type) {
        dist[type][i] = 0;
        que.push_back(i);
      }
    }
    for (int b = 0; b < (int) que.size(); b++) {
      for (int u : g[que[b]]) {
        if (dist[type][u] == -1) {
          dist[type][u] = dist[type][que[b]] + 1;
          que.push_back(u);
        }
      }
    }
  }
  vector<int> d(k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      d[j] = dist[j][i];
    }
    sort(d.begin(), d.end());
    long long sum = 0;
    for (int j = 0; j < s; j++) {
      sum += d[j];
    }
    if (i > 0) {
      cout << " ";
    }
    cout << sum;
  }
  cout << '\n';
  return 0;
}