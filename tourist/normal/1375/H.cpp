/**
 *    author:  tourist
 *    created: 04.07.2020 19:41:32       
**/
#undef _GLIBCXX_DEBUG

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

int n;
vector<int> a;
vector<pair<int, int>> gen;

vector<int> Solve(int L, int R, const vector<pair<int, int>>& qs) {
//  debug(L, R, qs);
  int q = (int) qs.size();
  vector<int> ret(q, -1);
  if (L == R) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == L) {
        pos = i;
      }
    }
    assert(pos != -1);
    for (int i = 0; i < q; i++) {
      ret[i] = pos;
    }
  } else {
    int M = (L + R) >> 1;
    vector<int> next_lower(n, n);
    vector<int> next_upper(n, n);
    vector<int> prev_lower(n, -1);
    vector<int> prev_upper(n, -1);
    for (int i = 0; i < n; i++) {
      if (L <= a[i] && a[i] <= M) {
        prev_lower[i] = i;
      } else {
        prev_lower[i] = (i == 0 ? -1 : prev_lower[i - 1]);
      }
      if (M < a[i] && a[i] <= R) {
        prev_upper[i] = i;
      } else {
        prev_upper[i] = (i == 0 ? -1 : prev_upper[i - 1]);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (L <= a[i] && a[i] <= M) {
        next_lower[i] = i;
      } else {
        next_lower[i] = (i == n - 1 ? n : next_lower[i + 1]);
      }
      if (M < a[i] && a[i] <= R) {
        next_upper[i] = i;
      } else {
        next_upper[i] = (i == n - 1 ? n : next_upper[i + 1]);
      }
    }
    vector<int> id_lower(q, -1);
    vector<int> id_upper(q, -1);
    {
      vector<pair<int, int>> qs_lower;
      for (int i = 0; i < q; i++) {
        int x = next_lower[qs[i].first];
        int y = prev_lower[qs[i].second];
        if (x <= y) {
          qs_lower.emplace_back(x, y);
        }
      }
      sort(qs_lower.begin(), qs_lower.end());
      qs_lower.resize(unique(qs_lower.begin(), qs_lower.end()) - qs_lower.begin());
      auto got_lower = Solve(L, M, qs_lower);
      for (int i = 0; i < q; i++) {
        int x = next_lower[qs[i].first];
        int y = prev_lower[qs[i].second];
        if (x <= y) {
          auto it = lower_bound(qs_lower.begin(), qs_lower.end(), make_pair(x, y));
          assert(it != qs_lower.end() && it->first == x && it->second == y);
          id_lower[i] = got_lower[(int) (it - qs_lower.begin())];
        }
      }
    }
    {
      vector<pair<int, int>> qs_upper;
      for (int i = 0; i < q; i++) {
        int x = next_upper[qs[i].first];
        int y = prev_upper[qs[i].second];
        if (x <= y) {
          qs_upper.emplace_back(x, y);
        }
      }
      sort(qs_upper.begin(), qs_upper.end());
      qs_upper.resize(unique(qs_upper.begin(), qs_upper.end()) - qs_upper.begin());
      auto got_upper = Solve(M + 1, R, qs_upper);
      for (int i = 0; i < q; i++) {
        int x = next_upper[qs[i].first];
        int y = prev_upper[qs[i].second];
        if (x <= y) {
          auto it = lower_bound(qs_upper.begin(), qs_upper.end(), make_pair(x, y));
          assert(it != qs_upper.end() && it->first == x && it->second == y);
          id_upper[i] = got_upper[(int) (it - qs_upper.begin())];
        }
      }
    }
    for (int i = 0; i < q; i++) {
      assert(id_lower[i] != -1 || id_upper[i] != -1);
      if (id_lower[i] == -1) {
        ret[i] = id_upper[i];
        continue;
      }
      if (id_upper[i] == -1) {
        ret[i] = id_lower[i];
        continue;
      }
      ret[i] = (int) gen.size();
      gen.emplace_back(id_lower[i], id_upper[i]);
    }
  }
//  debug(L, R, ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> n >> q;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<pair<int, int>> qs(q);
  for (int i = 0; i < q; i++) {
    cin >> qs[i].first >> qs[i].second;
    --qs[i].first;
    --qs[i].second;
  }
  gen.assign(n, make_pair(-1, -1));
  auto res = Solve(0, n - 1, qs);
  cout << (int) gen.size() << '\n';
  for (int i = n; i < (int) gen.size(); i++) {
    cout << gen[i].first + 1 << " " << gen[i].second + 1 << '\n';
  }
  for (int i = 0; i < (int) res.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i] + 1;
  }
  cout << '\n';
  return 0;
}