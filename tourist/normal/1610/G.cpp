/**
 *    author:  tourist
 *    created: 23.11.2021 18:36:36       
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

struct hash61 {
  static const uint64_t md = (1LL << 61) - 1;
  static uint64_t step;
  static vector<uint64_t> pw;
 
  uint64_t addmod(uint64_t a, uint64_t b) const {
    a += b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t submod(uint64_t a, uint64_t b) const {
    a += md - b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t mulmod(uint64_t a, uint64_t b) const {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }
 
  void ensure_pw(int sz) {
    int cur = (int) pw.size();
    if (cur < sz) {
      pw.resize(sz);
      for (int i = cur; i < sz; i++) {
        pw[i] = mulmod(pw[i - 1], step);
      }
    }
  }
 
  vector<uint64_t> pref;
  int n;
 
  template<typename T>
  hash61(const T& s) {
    n = (int) s.size();
    ensure_pw(n + 1);
    pref.resize(n + 1);
    pref[0] = 1;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
    }
  }
 
  inline uint64_t operator()(const int from, const int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};
 
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);

hash61 hasher((string) "a");

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> bal(n + 1);
  bal[0] = n + 1;
  for (int i = 0; i < n; i++) {
    bal[i + 1] = bal[i] + (s[i] == '(' ? 1 : -1);
  }
  const int LOG = 20;
  vector<uint64_t> coeff(LOG);
  coeff[0] = hash61::step;
  for (int i = 1; i < LOG; i++) {
    coeff[i] = hasher.mulmod(coeff[i - 1], coeff[i - 1]);
  }
  vector<vector<int>> pr(n + 1, vector<int>(LOG, -1));
  vector<vector<uint64_t>> ph(n + 1, vector<uint64_t>(LOG, 0));
  vector<char> pc(n + 1, ' ');
  int cnt = 1;
  vector<int> node(n + 1);
  node[n] = 0;
  auto AddNode = [&](int x, char c) {
    int id = cnt++;
    pc[id] = c;
    pr[id][0] = x;
    ph[id][0] = (uint64_t) c;
    for (int j = 1; j < LOG; j++) {
      pr[id][j] = pr[pr[id][j - 1]][j - 1];
      if (pr[id][j] == -1) {
        break;
      }
      ph[id][j] = hasher.addmod(hasher.mulmod(ph[id][j - 1], coeff[j - 1]), ph[pr[id][j - 1]][j - 1]);
    }
    return id;
  };
  vector<int> last(2 * n + 3, -1);
  last[bal[n]] = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ')') {
      node[i] = AddNode(node[i + 1], ')');
    } else {
      int j = last[bal[i]];
      if (j != -1 && (last[bal[i] - 1] == -1 || last[bal[i] - 1] > j)) {
        int x = node[i + 1];
        int y = node[j];
        if (y == 0) {
          node[i] = node[j];
        } else {
          if (pc[y] == ')') {
            node[i] = AddNode(node[i + 1], '(');
          } else {
            y = pr[y][0];
            for (int q = LOG - 1; q >= 0; q--) {
              if (pr[x][q] != -1 && pr[y][q] != -1 && ph[x][q] == ph[y][q]) {
                x = pr[x][q];
                y = pr[y][q];
              }
            }
            if (pr[x][0] == -1) {
              node[i] = AddNode(node[i + 1], '(');
            } else {
              if (pr[y][0] == -1) {
                node[i] = node[j];
              } else {
                assert(pc[x] != pc[y]);
                if (pc[x] < pc[y]) {
                  node[i] = AddNode(node[i + 1], '(');
                } else {
                  node[i] = node[j];
                }
              }
            }
          }
        }
      } else {
        node[i] = AddNode(node[i + 1], '(');
      }
    }
    last[bal[i]] = i;
  }
  int x = node[0];
  while (x != 0) {
    cout << pc[x];
    x = pr[x][0];
  }
  cout << '\n';
  return 0;
}