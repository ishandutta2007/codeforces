/**
 *    author:  tourist
 *    created: 17.02.2020 18:42:13       
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> spec(n, 0);
  for (int i = 0; i < k; i++) {
    int foo;
    cin >> foo;
    --foo;
    spec[foo] = 1;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> a(n, -1);
  vector<int> b(n, -1);
  for (int rot = 0; rot < 2; rot++) {
    vector<int> que(1, (rot == 0 ? 0 : n - 1));
    vector<int>& dist = (rot == 0 ? a : b);
    dist[que[0]] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      for (int j : g[que[b]]) {
        if (dist[j] == -1) {
          que.push_back(j);
          dist[j] = dist[que[b]] + 1;
        }
      }
    }
  }
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    if (spec[i]) {
      v.emplace_back(a[i], b[i]);
    }
  }
  int sz = (int) v.size();
  sort(v.begin(), v.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
    return x.first - x.second < y.first - y.second;
  });
  int ans = 0;
  int mx = v[0].first;
  for (int i = 1; i < sz; i++) {
    ans = max(ans, mx + 1 + v[i].second);
    mx = max(mx, v[i].first);
  }
  ans = min(ans, a[n - 1]);
  cout << ans << '\n';
  return 0;
}