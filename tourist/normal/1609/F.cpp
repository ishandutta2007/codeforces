/**
 *    author:  tourist
 *    created: 28.11.2021 18:07:07       
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

static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;

  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }
 
  inline void tie(int) {}

  inline explicit operator bool() {
    return cur != -1;
  }

  inline static bool is_blank(char c) {
    return c <= ' ';
  }

  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }
 
  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }
  
  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }
 
  template <typename T>
  inline FastInput& read_integer(T& n) {
    // unsafe, doesn't check that characters are actually digits
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }
  
  #if !defined(_WIN32) || defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    // not sure if really fast, for compatibility only
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;

#define cin fast_input

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> pc(n);
  for (int i = 0; i < n; i++) {
    pc[i] = __builtin_popcountll(a[i]);
  }
  const int M = 62;
  vector<vector<tuple<int, int, int>>> segs_min(M);
  vector<vector<tuple<int, int, int>>> segs_max(M);
  vector<int> st_min(1, -1);
  vector<int> st_max(1, -1);
  auto CountOne = [&](const vector<tuple<int, int, int>>& v, int up) {
    auto it = lower_bound(v.begin(), v.end(), make_tuple(up + 1, -1, -1));
    int res = (it == v.begin() ? 0 : get<2>(*prev(it)));
    if (it != v.end() && up >= get<1>(*it)) {
      res += up - get<1>(*it) + 1;
    }
    return res;
  };
  auto Count = [&](const vector<tuple<int, int, int>>& v, int L, int R) {
    return CountOne(v, R) - CountOne(v, L - 1);
  };
  int cc = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (st_min.size() > 1 && a[st_min.back()] > a[i]) {
      cc -= Count(segs_max[pc[st_min.back()]], st_min[st_min.size() - 2] + 1, st_min.back());
      segs_min[pc[st_min.back()]].pop_back();
      st_min.pop_back();
    }
    cc += Count(segs_max[pc[i]], st_min.back() + 1, i);
    segs_min[pc[i]].emplace_back(i, st_min.back() + 1, (i - st_min.back()) + (segs_min[pc[i]].empty() ? 0 : get<2>(segs_min[pc[i]].back())));
    st_min.push_back(i);

    while (st_max.size() > 1 && a[st_max.back()] < a[i]) {
      cc -= Count(segs_min[pc[st_max.back()]], st_max[st_max.size() - 2] + 1, st_max.back());
      segs_max[pc[st_max.back()]].pop_back();
      st_max.pop_back();
    }
    cc += Count(segs_min[pc[i]], st_max.back() + 1, i);
    segs_max[pc[i]].emplace_back(i, st_max.back() + 1, (i - st_max.back()) + (segs_max[pc[i]].empty() ? 0 : get<2>(segs_max[pc[i]].back())));
    st_max.push_back(i);

    ans += cc;
  }
  cout << ans << '\n';
  return 0;
}