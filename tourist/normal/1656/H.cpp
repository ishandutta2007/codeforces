/**
 *    author:  tourist
 *    created: 24.03.2022 18:51:58       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
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

static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE *out = stdout;

  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }

  ~FastOutput() {
    fwrite(buf, 1, buf_pos, out);
  }

  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }

  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }
 
  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int) s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }
 
  template <typename T>
  inline char* integer_to_string(T n) {
    // beware of TMP_SIZE
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char) ('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }

  #if !defined(_WIN32) || defined(_WIN64)
  inline char* stringify(__int128 n) {
    return integer_to_string(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }

  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;

#define cout fast_output

// https://github.com/bicsi/kactl/blob/master/content/data-structures/SegmentTree.h

__int128 lcm(__int128 a, __int128 b) {
  return a / __gcd(a, b) * b;
}

struct SegmTree {
  vector<__int128> T; int n;
  SegmTree(int n) : T(2 * n, 1), n(n) {}
  
  void Update(int pos, __int128 val) {
    for (T[pos += n] = val; pos > 1; pos /= 2)
      T[pos / 2] = lcm(T[pos], T[pos ^ 1]);
  }
  
  __int128 Query(int b, int e) {
    __int128 res = 1;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) res = lcm(res, T[b++]);
      if (e % 2) res = lcm(res, T[--e]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<__int128> a(n);
    vector<__int128> b(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    vector<SegmTree> sa(n, SegmTree(m));
    vector<SegmTree> sb(m, SegmTree(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        auto x = __gcd(a[i], b[j]);
        sa[i].Update(j, x);
        sb[j].Update(i, x);
      }
    }
    vector<bool> ka(n, false);
    vector<bool> kb(m, false);
    vector<int> que;
    for (int i = 0; i < n; i++) {
      if (sa[i].Query(0, m) != a[i]) {
        ka[i] = true;
        que.push_back(i);
      }
    }
    for (int i = 0; i < m; i++) {
      if (sb[i].Query(0, n) != b[i]) {
        kb[i] = true;
        que.push_back(~i);
      }
    }
    for (int bb = 0; bb < (int) que.size(); bb++) {
      int id = que[bb];
      if (id >= 0) {
        for (int j = 0; j < m; j++) {
          if (!kb[j]) {
            sb[j].Update(id, 1);
            if (sb[j].Query(0, n) != b[j]) {
              kb[j] = true;
              que.push_back(~j);
            }
          }
        }
      } else {
        id = ~id;
        for (int i = 0; i < n; i++) {
          if (!ka[i]) {
            sa[i].Update(id, 1);
            if (sa[i].Query(0, m) != a[i]) {
              ka[i] = true;
              que.push_back(i);
            }
          }
        }
      }
    }
    vector<__int128> ra, rb;
    for (int i = 0; i < n; i++) {
      if (!ka[i]) {
        ra.push_back(a[i]);
      }
    }
    for (int i = 0; i < m; i++) {
      if (!kb[i]) {
        rb.push_back(b[i]);
      }
    }
    if (ra.empty() || rb.empty()) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      cout << ra.size() << " " << rb.size() << '\n';
      for (int i = 0; i < (int) ra.size(); i++) {
        cout << ra[i] << " \n"[i == (int) ra.size() - 1];
      }
      for (int i = 0; i < (int) rb.size(); i++) {
        cout << rb[i] << " \n"[i == (int) rb.size() - 1];
      }
    }
  }
  return 0;
}