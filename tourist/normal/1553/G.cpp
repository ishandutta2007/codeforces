/**
 *    author:  tourist
 *    created: 22.07.2021 18:18:20       
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = *max_element(a.begin(), a.end()) + 1;
  vector<int> id(mx + 1, -1);
  for (int i = 0; i < n; i++) {
    id[a[i]] = i;
  }
  dsu d(n);
  for (int x = 2; x <= mx; x++) {
    int last = -1;
    for (int y = x; y <= mx; y += x) {
      if (id[y] != -1) {
        if (last != -1) {
          d.unite(last, id[y]);
        }
        last = id[y];
      }
    }
  }
  vector<vector<int>> who(n);
  for (int i = 0; i < n; i++) {
    who[i].push_back(d.get(i));
  }
  vector<pair<int, int>> ones;
  for (int x = 2; x <= mx; x++) {
    int any = -1;
    for (int y = x; y <= mx; y += x) {
      if (id[y] != -1) {
        any = d.get(id[y]);
        break;
      }
    }
    if (any == -1) {
      continue;
    }
    for (int y = x; y <= mx; y += x) {
      if (id[y - 1] != -1) {
        int a = id[y - 1];
        who[a].push_back(any);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    sort(who[i].begin(), who[i].end());
    who[i].resize(unique(who[i].begin(), who[i].end()) - who[i].begin());
    for (int j1 = 0; j1 < (int) who[i].size(); j1++) {
      for (int j2 = j1 + 1; j2 < (int) who[i].size(); j2++) {
        ones.emplace_back(who[i][j1], who[i][j2]);
      }
    }
    debug(i, who[i]);
  }
  for (int i = 0; i < n; i++) debug(i, d.get(i));
  sort(ones.begin(), ones.end());
  ones.resize(unique(ones.begin(), ones.end()) - ones.begin());
  debug(ones);
  while (tt--) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    a = d.get(a);
    b = d.get(b);
    if (a == b) {
      cout << 0 << '\n';
      continue;
    }
    if (a > b) {
      swap(a, b);
    }
    auto it = lower_bound(ones.begin(), ones.end(), make_pair(a, b));
    if (it != ones.end() && it->first == a && it->second == b) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 << '\n';
  }
  return 0;
}