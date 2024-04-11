/**
 *    author:  tourist
 *    created: 10.03.2021 15:14:06       
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
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<pair<int, int>> segs;
  int beg = 0;
  while (beg < n - 1) {
    int sign = (p[beg] < p[beg + 1]);
    int end = beg + 1;
    while (end + 1 < n && (p[end] < p[end + 1]) == sign) {
      ++end;
    }
    segs.emplace_back(beg, end);
    beg = end;
  }
  vector<int> lens;
  for (auto& s : segs) {
    lens.push_back(s.second - s.first);
  }
  int id = 0;
  for (int i = 1; i < (int) segs.size(); i++) {
    if (lens[i] > lens[id]) {
      id = i;
    }
  }
  vector<int> down_left(n);
  vector<int> up_left(n);
  for (int i = 1; i < n; i++) {
    if (p[i - 1] < p[i]) {
      down_left[i] = down_left[i - 1] + 1;
      up_left[i] = 0;
    } else {
      down_left[i] = 0;
      up_left[i] = up_left[i - 1] + 1;
    }
  }
  vector<int> down_right(n);
  vector<int> up_right(n);
  for (int i = n - 2; i >= 0; i--) {
    if (p[i + 1] < p[i]) {
      down_right[i] = down_right[i + 1] + 1;
      up_right[i] = 0;
    } else {
      down_right[i] = 0;
      up_right[i] = up_right[i + 1] + 1;
    }
  }
  int ans = 0;
  for (int x : {segs[id].first, segs[id].second}) {
    debug(x);
    int L = x - down_left[x];
    int R = x + down_right[x];
    bool win = true;
    for (int y = 0; y < n; y++) {
      if (x == y) {
        continue;
      }
      if (y >= L && y < x) {
        bool can_win = false;
        {
          if ((x - y) % 2 == 0) {
            if (down_left[x] > up_left[y]) {
              can_win = true;
            }
          }
        }
        {
          int them = down_right[x];
          int us = max(up_left[y], up_right[y]);
          if (them > us) {
            can_win = true;
          }
        }
        if (!can_win) {
          win = false;
          break;
        }
        continue;
      }
      if (y > x && y <= R) {
        bool can_win = false;
        {
          if ((y - x) % 2 == 0) {
            if (down_right[x] > up_right[y]) {
              can_win = true;
            }
          }
        }
        {
          int them = down_left[x];
          int us = max(up_right[y], up_left[y]);
          if (them > us) {
            can_win = true;
          }
        }
        if (!can_win) {
          win = false;
          break;
        }
        continue;
      }
      int them = max(down_left[x], down_right[x]);
      int us = max(up_left[y], up_right[y]);
      if (us >= them) {
        win = false;
        break;
      }
    }
    if (win) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}