/**
 *    author:  tourist
 *    created: 18.09.2021 18:04:02       
**/
#undef _GLIBCXX_DEBUG

#undef LOCAL

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

namespace radix {

vector<int> p(65537);

template<typename T>
void SortShift(vector<T>& a, vector<T>& new_a, int shift) {
  assert(a.size() == new_a.size());
  int n = static_cast<int>(a.size());
  fill(p.begin(), p.end(), 0);
  for (int i = 0; i < n; i++) p[1 + ((a[i] >> shift) & 0xffff)]++;
  for (int i = 1; i <= 65536; i++) p[i] += p[i - 1];
  for (int i = 0; i < n; i++) new_a[p[(a[i] >> shift) & 0xffff]++] = a[i];
}

void Sort(vector<int32_t>& a) {
  constexpr int32_t flip = static_cast<int32_t>(1) << 31;
  for (auto& aa : a) aa ^= flip;
  vector<int32_t> b(a.size());
  SortShift(a, b, 0);
  SortShift(b, a, 16);
  for (auto& aa : a) aa ^= flip;
}

void Sort(vector<uint32_t>& a) {
  vector<uint32_t> b(a.size());
  SortShift(a, b, 0);
  SortShift(b, a, 16);
}

void Sort(vector<int64_t>& a) {
  constexpr int64_t flip = static_cast<int64_t>(1) << 63;
  for (auto& aa : a) aa ^= flip;
  vector<int64_t> b(a.size());
  SortShift(a, b, 0);
  SortShift(b, a, 16);
  SortShift(a, b, 32);
  SortShift(b, a, 48);
  for (auto& aa : a) aa ^= flip;
}

void Sort(vector<uint64_t>& a) {
  vector<uint64_t> b(a.size());
  SortShift(a, b, 0);
  SortShift(b, a, 16);
  SortShift(a, b, 32);
  SortShift(b, a, 48);
}

}  // namespace radix

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
  }
  vector<int> kb(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    kb[i] = (__builtin_popcount(i));
  }
  vector<int> side(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    side[i] = (kb[i] % 2);
  }
  vector<int64_t> all((1 << (n - 1)) * n);
  int ptr = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (side[i] == 0) {
      for (int j = 0; j < n; j++) {
        int ni = i ^ (1 << j);
        all[ptr] = ((long long) (a[i] + a[ni])) << (2 * n);
        all[ptr] += ((long long) i) << n;
        all[ptr] += ni;
        ptr += 1;
      }
    }
  }
  assert(ptr == (int) all.size());
  radix::Sort(all);
  reverse(all.begin(), all.end());
  k = min(k, (1 << (n - 1)));
  vector<int> used(1 << n, 0);
  vector<pair<int, int>> es;
  vector<int> vs;
  int ans = 0;
  ptr = 0;
  for (int iter = 0; iter < k; iter++) {
    int pi = -1, pj = -1;
    while (ptr < (int) all.size()) {
      int i = (int) ((all[ptr] >> n) & ((1 << n) - 1));
      int j = (int) (all[ptr] & ((1 << n) - 1));
      if (!used[i] && !used[j]) {
        pi = i;
        pj = j;
        break;
      }
      ptr += 1;
    }
    sort(vs.begin(), vs.end());
    int sz = (int) vs.size();
    vector<vector<int>> g(sz, vector<int>(sz, 0));
    for (int i = 0; i < sz; i++) {
      if (side[vs[i]] == 0) {
        for (int j = 0; j < sz; j++) {
          if (side[vs[j]] == 1 && kb[vs[i] ^ vs[j]] == 1) {
            g[i][j] = 1;
          }
        }
      }
    }
    for (auto& e : es) {
      int x = (int) (lower_bound(vs.begin(), vs.end(), e.first) - vs.begin());
      int y = (int) (lower_bound(vs.begin(), vs.end(), e.second) - vs.begin());
      g[x][y] ^= 1;
      g[y][x] ^= 1;
    }
    vector<int> opt(sz, -1);
    vector<int> who(sz, -1);
    for (int i = 0; i < sz; i++) {
      for (int bit = 0; bit < n; bit++) {
        int j = vs[i] ^ (1 << bit);
        if (!used[j] && a[j] > opt[i]) {
          opt[i] = a[j];
          who[i] = j;
        }
      }
    }
    debug(vs, es, g);
    vector<int> pr(sz, -1);
    vector<int> que(sz);
    int mi = -1, mj = -1, mx = -1;
    for (int start = 0; start < sz; start++) {
      if (side[vs[start]] == 1 && opt[start] >= 0) {
        fill(pr.begin(), pr.end(), -1);
        pr[start] = -2;
        int qIt = 0;
        int qSz = 1;
        que[0] = start;
        while (qIt < qSz) {
          int i = que[qIt++];
          for (int j = 0; j < sz; j++) {
            debug(i, j, pr, g[i][j]);
            if (g[i][j] && pr[j] == -1) {
              que[qSz++] = j;
              pr[j] = i;
            }
          }
        }
        for (int j = 0; j < sz; j++) {
          if (side[vs[j]] == 0 && pr[j] != -1 && opt[j] >= 0) {
            if (opt[start] + opt[j] > mx) {
              mx = opt[start] + opt[j];
              mi = start;
              mj = j;
            }
          }
        }
      }
    }
    if (pi == -1 || mx > a[pi] + a[pj]) {
      assert(mx >= 0);
      int start = mi;
      fill(pr.begin(), pr.end(), -1);
      pr[start] = -2;
      int qIt = 0;
      int qSz = 1;
      que[0] = start;
      while (qIt < qSz) {
        int i = que[qIt++];
        for (int j = 0; j < sz; j++) {
          if (g[i][j] && pr[j] == -1) {
            que[qSz++] = j;
            pr[j] = i;
          }
        }
      }
      debug(pr);
      auto Flip = [&](pair<int, int> p) {
        auto it = find(es.begin(), es.end(), p);
        if (it == es.end()) {
          es.push_back(p);
        } else {
          *it = es.back();
          es.pop_back();
        }
      };
      int at = mj;
      while (at != mi) {
        int x = vs[at];
        int y = vs[pr[at]];
        assert(side[x] != side[y]);
        if (side[x] == 1) {
          swap(x, y);
        }
        Flip(make_pair(x, y));
        at = pr[at];
      }
      es.emplace_back(who[mi], vs[mi]);
      es.emplace_back(vs[mj], who[mj]);
      used[who[mi]] = 1;
      used[who[mj]] = 1;
      vs.push_back(who[mi]);
      vs.push_back(who[mj]);
      ans += mx;
    } else {
      used[pi] = 1;
      used[pj] = 1;
      vs.push_back(pi);
      vs.push_back(pj);
      es.emplace_back(pi, pj);
      ans += a[pi] + a[pj];
    }
  }
  cout << ans << '\n';
  return 0;
}