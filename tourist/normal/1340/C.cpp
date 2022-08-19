/**
 *    author:  tourist
 *    created: 23.04.2020 18:27:32       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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
  int n, m;
  cin >> n >> m;
  vector<int> d(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  int g, r;
  cin >> g >> r;
  vector<vector<int>> dist(m, vector<int>(g + 1, -1));
  dist[0][g] = 0;
  vector<pair<int, int>> que;
  que.emplace_back(0, g);
  while (!que.empty()) {
    for (int b = 0; b < (int) que.size(); b++) {
      int i = que[b].first;
      int j = que[b].second;
      if (i > 0) {
        int go = d[i] - d[i - 1];
        if (j >= go) {
          if (dist[i - 1][j - go] == -1) {
            que.emplace_back(i - 1, j - go);
            dist[i - 1][j - go] = dist[i][j];
          }
        }
      }
      if (i < m - 1) {
        int go = d[i + 1] - d[i];
        if (j >= go) {
          if (dist[i + 1][j - go] == -1) {
            que.emplace_back(i + 1, j - go);
            dist[i + 1][j - go] = dist[i][j];
          }
        }
      }
    }
    vector<pair<int, int>> new_que;
    for (int b = 0; b < (int) que.size(); b++) {
      int j = que[b].second;
      if (j == 0) {
        int i = que[b].first;
        if (dist[i][g] == -1) {
          dist[i][g] = dist[i][0] + 1;
          new_que.emplace_back(i, g);
        }
      }
    }
    swap(que, new_que);
  }
  const long long inf = (long long) 1e18;
  long long ans = inf;
  for (int i = 0; i <= g; i++) {
    if (dist[m - 1][i] != -1) {
      long long cur = (long long) dist[m - 1][i] * (g + r) + (g - i);
      ans = min(ans, cur);
    }
  }
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}