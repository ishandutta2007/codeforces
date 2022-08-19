/**
 *    author:  tourist
 *    created: 09.08.2021 18:25:28       
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n = 8;
    vector<vector<bool>> a(n, vector<bool>(n, true));
    pair<int, int> done = {787788, 787788};
    auto MakeQuery = [&](int r, int c) {
      cout << r + 1 << " " << c + 1 << endl;
      string s;
      cin >> s;
      if (s == "Done") return done;
      int dr = 0;
      int dc = 0;
      if (s.find("Right") != string::npos) dc += 1;
      if (s.find("Left") != string::npos) dc -= 1;
      if (s.find("Down") != string::npos) dr += 1;
      if (s.find("Up") != string::npos) dr -= 1;
      return make_pair(dr, dc);
    };
    int mr = 0, mc = 0;
    auto Go = [&](int r, int c) {
      mr = r;
      mc = c;
      assert(0 <= r && r < n && 0 <= c && c < n);
      auto p = MakeQuery(r, c);
      if (p == done) {
        return p;
      }
      vector<vector<bool>> new_a(n, vector<bool>(n, false));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (a[i][j]) {
            int ni = i + p.first;
            int nj = j + p.second;
            if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
              if (ni == r || nj == c || ni - nj == r - c || ni + nj == r + c) {
                continue;
              }
              new_a[ni][nj] = true;
            }
          }
        }
      }
      swap(a, new_a);
      return p;
    };
    if (Go(0, 0) == done) {
      continue;
    }
    while (true) {
      int gi = -1, gj = -1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (a[i][j]) {
            gi = i;
            gj = j;
            break;
          }
        }
        if (gi != -1) {
          break;
        }
      }
      if (gi == -1) {
        assert(false);
      }
      if (mr != gi - 1) {
        if (Go(max(0, gi - 1), mc) == done) {
          break;
        }
        continue;
      }
      auto p = Go(mr, gj);
      if (p == done) {
        break;
      }
      while (p != done && p.first == 1) {
        int nr = mr + p.first;
        int nc = mc + p.second;
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
          break;
        }
        p = Go(mr + p.first, mc + p.second);
      }
      if (p == done) {
        break;
      }
    }
  }
  return 0;
}