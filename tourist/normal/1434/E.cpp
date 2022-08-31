/**
 *    author:  tourist
 *    created: 25.10.2020 14:45:24       
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

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

const int MAX = 100010;
int bound[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int x = 0;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    {
      int ptr = -1;
      for (int val = 0; val < MAX; val++) {
        if (ptr + 1 < n && v[ptr + 1] == val) {
          ++ptr;
        }
        bound[val] = ptr;
      }
    }
    vector<vector<int>> who(1, vector<int>(n, -1));
    vector<dsu> d(1, dsu(n + 1));
    vector<bool> seen;
    for (int i = n - 1; i >= 0; i--) {
      int start = 0;
      int j = 0;
      while (start < i) {
        if (j == (int) who.size()) {
          who.emplace_back(n, -1);
          d.emplace_back(n + 1);
        }
        int finish = i - 1;
        int tmp = who[j][i];
        if (tmp != -1) {
          int val = v[i] - (v[tmp] - v[i]);
          finish = (val <= 0 ? -1 : bound[val]);
        }
//        debug(i, j, start, finish);
        if (start <= finish) {
          int pos = d[j].get(start);
          while (pos <= finish) {
            who[j][pos] = i;
            d[j].unite(pos, pos + 1);
            pos = d[j].get(pos);
          }
          start = finish + 1;
        }
        ++j;
      }
      int g = 0;
      while (g < (int) who.size() && who[g][i] != -1) {
        ++g;
      }
      if (g >= (int) seen.size()) {
        seen.resize(g + 1);
      }
      seen[g] = true;
    }
    int g = 0;
    while (g < (int) seen.size() && seen[g]) {
      ++g;
    }
    x ^= g;
    debug(g);
  }
  cout << (x > 0 ? "YES" : "NO") << '\n';
  return 0;
}