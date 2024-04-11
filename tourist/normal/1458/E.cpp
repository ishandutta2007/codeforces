/**
 *    author:  tourist
 *    created: 19.12.2020 13:02:41       
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
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  const int M = (int) 1e9;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    mp[x[i]].push_back(y[i]);
  }
  mp[M + 1].push_back(-1);
  set<pair<int, int>> s;
  s.emplace(0, 2 * M);
  vector<tuple<int, int, int>> res;
  int last = -1;
  for (auto& p : mp) {
    sort(p.second.begin(), p.second.end());
    int row = p.first;
    int from = last + 1;
    int to = row - 1;
    while (from <= to) {
      auto it = s.begin();
      int it1 = it->first;
      int it2 = it->second;
      int len = it->second - it->first + 1;
      if (len <= to - from + 1) {
        res.emplace_back(from, from + len - 1, it->first);
        from += len;
        s.erase(it);
        continue;
      }
      res.emplace_back(from, to, it->first);
      s.erase(it);
      s.emplace(it1 + (to - from + 1), it2);
      break;
    }
    if (p.first > M) {
      break;
    }
    for (int j : p.second) {
      auto it = s.lower_bound(make_pair(j + 1, -1));
      if (it != s.begin()) {
        it = prev(it);
        int L = it->first;
        int R = it->second;
        if (L <= j && j <= R) {
          s.erase(it);
          if (L < j) {
            s.emplace(L, j - 1);
          }
          if (j < R) {
            s.emplace(j + 1, R);
          }
        }
      }
    }
    auto it = s.begin();
    if (it->first < p.second[0]) {
      int L = it->first;
      int R = it->second;
      p.second.insert(p.second.begin(), L);
      s.erase(it);
      if (L < R) {
        s.emplace(L + 1, R);
      }
    }
    last = row;
  }
  while (m--) {
    int x, y;
    cin >> x >> y;
    auto it = mp.find(x);
    if (it != mp.end()) {
      auto ti = lower_bound(it->second.begin(), it->second.end(), y);
      if (ti != it->second.end() && (*ti) == y) {
        cout << "LOSE" << '\n';
      } else {
        cout << "WIN" << '\n';
      }
    } else {
      auto ti = lower_bound(res.begin(), res.end(), make_tuple(x + 1, -1, -1));
      assert(ti != res.begin());
      ti = prev(ti);
      assert(get<0>(*ti) <= x && x <= get<1>(*ti));
      int val = get<2>(*ti) + (x - get<0>(*ti));
      if (val == y) {
        cout << "LOSE" << '\n';
      } else {
        cout << "WIN" << '\n';
      }
    }
  }
  return 0;
}