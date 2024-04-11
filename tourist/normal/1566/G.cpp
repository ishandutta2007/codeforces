/**
 *    author:  tourist
 *    created: 12.09.2021 18:23:49       
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

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick() {}

  void init(int _n) {
    n = _n;
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m), c(m);
  map<pair<int, int>, int> wei;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i]; --b[i];
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
    wei[{a[i], b[i]}] = c[i];
  }
  int q;
  cin >> q;
  vector<int> qt(q), qa(q), qb(q), qc(q);
  for (int i = 0; i < q; i++) {
    cin >> qt[i] >> qa[i] >> qb[i];
    --qa[i]; --qb[i];
    if (qa[i] > qb[i]) {
      swap(qa[i], qb[i]);
    }
    if (qt[i] == 0) {
      qc[i] = wei[{qa[i], qb[i]}];
    } else {
      cin >> qc[i];
      wei[{qa[i], qb[i]}] = qc[i];
    }
  }
  vector<vector<tuple<int, int, int>>> nei(n);
  vector<tuple<int, int, int>> aux;
  for (int i = 0; i < m; i++) {
    nei[a[i]].emplace_back(c[i], a[i], b[i]);
    nei[b[i]].emplace_back(c[i], a[i], b[i]);
    aux.emplace_back(c[i], a[i], b[i]);
  }
  for (int i = 0; i < q; i++) {
    nei[qa[i]].emplace_back(qc[i], qa[i], qb[i]);
    nei[qb[i]].emplace_back(qc[i], qa[i], qb[i]);
    aux.emplace_back(qc[i], qa[i], qb[i]);
  }
  for (int i = 0; i < n; i++) {
    sort(nei[i].begin(), nei[i].end());
    nei[i].resize(unique(nei[i].begin(), nei[i].end()) - nei[i].begin());
  }
  sort(aux.begin(), aux.end());
  aux.resize(unique(aux.begin(), aux.end()) - aux.begin());
  vector<set<tuple<int, int, int>>> s(n);
  set<pair<long long, int>> threes;
  auto AddThree = [&](int i) {
    if (s[i].size() >= 3) {
      auto it = s[i].begin();
      long long v0 = get<0>(*it);
      it = next(it);
      long long v1 = get<0>(*it);
      it = next(it);
      long long v2 = get<0>(*it);
      threes.emplace(v0 + v1 + v2, i);
    }
  };
  auto RemoveThree = [&](int i) {
    if (s[i].size() >= 3) {
      auto it = s[i].begin();
      long long v0 = get<0>(*it);
      it = next(it);
      long long v1 = get<0>(*it);
      it = next(it);
      long long v2 = get<0>(*it);
      threes.erase({v0 + v1 + v2, i});
    }
  };
  set<tuple<int, int, int>> all;
  fenwick<int> fenw;
  fenw.init((int) aux.size());
  vector<fenwick<int>> ff(n);
  for (int i = 0; i < n; i++) {
    ff[i].init((int) nei[i].size());
  }
  auto AddEdge = [&](int A, int B, int C) {
    all.emplace(C, A, B);

    RemoveThree(A);
    RemoveThree(B);
    s[A].emplace(C, A, B);
    s[B].emplace(C, A, B);
    AddThree(A);
    AddThree(B);

    {
      auto it = lower_bound(aux.begin(), aux.end(), make_tuple(C, A, B));
      assert(it != aux.end() && ((*it) == make_tuple(C, A, B)));
      fenw.modify((int) (it - aux.begin()), +1);
    }

    {
      auto it = lower_bound(nei[A].begin(), nei[A].end(), make_tuple(C, A, B));
      assert(it != nei[A].end() && ((*it) == make_tuple(C, A, B)));
      ff[A].modify((int) (it - nei[A].begin()), +1);
    }

    {
      auto it = lower_bound(nei[B].begin(), nei[B].end(), make_tuple(C, A, B));
      assert(it != nei[B].end() && ((*it) == make_tuple(C, A, B)));
      ff[B].modify((int) (it - nei[B].begin()), +1);
    }
  };
  auto RemoveEdge = [&](int A, int B, int C) {
    all.erase({C, A, B});

    RemoveThree(A);
    RemoveThree(B);
    s[A].erase({C, A, B});
    s[B].erase({C, A, B});
    AddThree(A);
    AddThree(B);

    {
      auto it = lower_bound(aux.begin(), aux.end(), make_tuple(C, A, B));
      assert(it != aux.end() && ((*it) == make_tuple(C, A, B)));
      fenw.modify((int) (it - aux.begin()), -1);
    }

    {
      auto it = lower_bound(nei[A].begin(), nei[A].end(), make_tuple(C, A, B));
      assert(it != nei[A].end() && ((*it) == make_tuple(C, A, B)));
      ff[A].modify((int) (it - nei[A].begin()), -1);
    }

    {
      auto it = lower_bound(nei[B].begin(), nei[B].end(), make_tuple(C, A, B));
      assert(it != nei[B].end() && ((*it) == make_tuple(C, A, B)));
      ff[B].modify((int) (it - nei[B].begin()), -1);
    }
  };
  for (int i = 0; i < m; i++) {
    AddEdge(a[i], b[i], c[i]);
  }
  for (int i = 0; i <= q; i++) {
    long long ans = (long long) 1e18;
    if (!threes.empty()) {
      ans = min(ans, threes.begin()->first);
    }
//    debug(threes);
//    debug(all);
    assert(!all.empty());
    auto edge = *all.begin();
    int w = get<0>(edge);
    int x = get<1>(edge);
    int y = get<2>(edge);
    if (s[x].size() >= 2 && s[y].size() >= 2) {
      auto it_x = s[x].begin();
      auto it_y = s[y].begin();
      assert((*it_x) == make_tuple(w, x, y) && (*it_y) == make_tuple(w, x, y));
      it_x = next(it_x);
      it_y = next(it_y);
      int vx = (get<1>(*it_x) ^ get<2>(*it_x) ^ x);
      int vy = (get<1>(*it_y) ^ get<2>(*it_y) ^ y);
      if (vx != vy) {
        ans = min(ans, (long long) get<0>(*it_x) + get<0>(*it_y));
      } else {
        if (s[x].size() >= 3) {
          ans = min(ans, (long long) get<0>(*next(it_x)) + get<0>(*it_y));
        }
        if (s[y].size() >= 3) {
          ans = min(ans, (long long) get<0>(*it_x) + get<0>(*next(it_y)));
        }
      }
    }

    {
      auto it = lower_bound(aux.begin(), aux.end(), make_tuple(w, x, y));
      assert(it != aux.end() && ((*it) == make_tuple(w, x, y)));
      int id = (int) (it - aux.begin());
      int low = id;
      int high = (int) aux.size();
      while (low < high) {
        int mid = (low + high) >> 1;
        int total = fenw.get(mid);
        int inc = 0;
        for (int rot = 0; rot < 2; rot++) {
          int ver = (rot == 0 ? x : y);
          int pos = (int) (upper_bound(nei[ver].begin(), nei[ver].end(), aux[mid]) - nei[ver].begin());
          inc += ff[ver].get(pos - 1);
        }
        inc -= 1;
        if (total > inc) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      if (low < (int) aux.size()) {
        ans = min(ans, (long long) w + get<0>(aux[low]));
      }
    }

    cout << ans << '\n';
    if (i == q) {
      break;
    }
    if (qt[i] == 1) {
      AddEdge(qa[i], qb[i], qc[i]);
    } else {
      RemoveEdge(qa[i], qb[i], qc[i]);
    }
  }
  return 0;
}