/**
 *    author:  tourist
 *    created: 12.04.2020 18:40:07       
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
  vector<vector<bool>> g(n, vector<bool>(n, false));
  vector<int> din(n, 0);
  vector<int> dout(n, 0);
  for (int i = 0; i < n; i++) {
    string foo;
    cin >> foo;
    for (int j = 0; j < (n >> 2); j++) {
      char c = foo[j];
      int d = (c <= '9' ? (int) (c - '0') : (int) (c - 'A' + 10));
      for (int k = 0; k < 4; k++) {
        if (d & (1 << (3 - k))) {
          int x = (j << 2) | k;
          g[i][x] = true;
          dout[i] += 1;
          din[x] += 1;
        }
      }
    }
  }
  const long long none = 614LL * n;
  long long ans = 0;
  vector<bool> alive(n, true);
  for (int rm = n; rm >= 1; rm--) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      if (alive[i] && dout[i] == rm - 1) {
        alive[i] = false;
        ans += (1 + none) * (rm - 1);
        found = true;
        break;
      }
    }
    if (!found) {
      vector<int> all;
      for (int i = 0; i < n; i++) {
        if (alive[i]) {
          all.push_back(i);
        }
      }
      debug(all);
      assert((int) all.size() == rm);
      vector<int> used(n, 0);
      vector<int> seq(1, all[0]);
      used[seq[0]] += 1;
      vector<int> add;
      vector<bool> in_seq(n, false);
      in_seq[seq[0]] = true;
      for (int it = 0; it < rm; it++) {
        assert(it < (int) seq.size());
        int v = seq[it];
        in_seq[v] = false;
        add.clear();
        for (int j = 0; j < n; j++) {
          if (v != j && !in_seq[j] && alive[j] && !g[v][j]) {
            assert(used[j] < 2);
            used[j] += 1;
            add.push_back(j);
          }
        }
        sort(add.begin(), add.end(), [&](int i, int j) {
          return g[j][i];
        });
        for (int u : add) {
          seq.push_back(u);
          in_seq[u] = true;
        }
      }
      seq.resize(rm);
      reverse(seq.begin(), seq.end());
      for (int i = 0; i < rm; i++) {
        int cc = 0;
        while (cc < rm - 1) {
          ans += rm - 1 - cc;
          cc += dout[seq[(i + cc) % rm]];
        }
      }
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}