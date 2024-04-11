/**
 *    author:  tourist
 *    created: 24.07.2020 18:10:56       
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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<pair<int, int>> pos(h * w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      --a[i][j];
      pos[a[i][j]] = make_pair(i, j);
    }
  }
  vector<vector<int>> b(h, vector<int>(w, -1));
  int pi = -1;
  int pj = -1;
  vector<pair<int, int>> cells;
  int ptr = 0;
  for (int val = h * w - 1; val >= 0; val--) {
    for (int i = 0; i < h; i++) debug(b[i]);
    debug(pi, pj, cells);
    auto& at = pos[val];
    int vi = at.first;
    int vj = at.second;
    bool row_max = true;
    for (int j = 0; j < w; j++) {
      row_max &= (a[vi][j] <= val);
    }
    bool col_max = true;
    for (int i = 0; i < h; i++) {
      col_max &= (a[i][vj] <= val);
    }
    debug(val, vi, vj, row_max, col_max);
    if (row_max && col_max) {
      b[++pi][++pj] = val;
      for (int j = pj - 1; j >= 0; j--) {
        if (b[pi][j] == -1) {
          cells.emplace_back(pi, j);
        }
      }
      for (int i = pi - 1; i >= 0; i--) {
        if (b[i][pj] == -1) {
          cells.emplace_back(i, pj);
        }
      }
      continue;
    }
    if (row_max) {
      b[++pi][pj] = val;
      for (int j = pj - 1; j >= 0; j--) {
        if (b[pi][j] == -1) {
          cells.emplace_back(pi, j);
        }
      }
      continue;
    }
    if (col_max) {
      b[pi][++pj] = val;
      for (int i = pi - 1; i >= 0; i--) {
        if (b[i][pj] == -1) {
          cells.emplace_back(i, pj);
        }
      }
      continue;
    }
    assert(ptr < (int) cells.size());
    b[cells[ptr].first][cells[ptr].second] = val;
    ++ptr;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << b[i][j] + 1;
    }
    cout << '\n';
  }
  return 0;
}