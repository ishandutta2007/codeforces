/**
 *    author:  tourist
 *    created: 23.02.2020 20:13:42       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<int> suffix_array(int n, const T &s, int char_bound) {
  vector<int> a(n);
  if (n == 0) {
    return a;
  }
  if (char_bound != -1) {
    vector<int> aux(char_bound, 0);
    for (int i = 0; i < n; i++) {
      aux[s[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < char_bound; i++) {
      int add = aux[i];
      aux[i] = sum;
      sum += add;
    }
    for (int i = 0; i < n; i++) {
      a[aux[s[i]]++] = i;
    }
  } else {
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&s](int i, int j) { return s[i] < s[j]; });
  }
  vector<int> sorted_by_second(n);
  vector<int> ptr_group(n);
  vector<int> new_group(n);
  vector<int> group(n);
  group[a[0]] = 0;
  for (int i = 1; i < n; i++) {
    group[a[i]] = group[a[i - 1]] + (!(s[a[i]] == s[a[i - 1]]));
  }
  int cnt = group[a[n - 1]] + 1;
  int step = 1;
  while (cnt < n) {
    int at = 0;
    for (int i = n - step; i < n; i++) {
      sorted_by_second[at++] = i;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] - step >= 0) {
        sorted_by_second[at++] = a[i] - step;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      ptr_group[group[a[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      int x = sorted_by_second[i];
      a[ptr_group[group[x]]++] = x;
    }
    new_group[a[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (group[a[i]] != group[a[i - 1]]) {
        new_group[a[i]] = new_group[a[i - 1]] + 1;
      } else {
        int pre = (a[i - 1] + step >= n ? -1 : group[a[i - 1] + step]);
        int cur = (a[i] + step >= n ? -1 : group[a[i] + step]);
        new_group[a[i]] = new_group[a[i - 1]] + (pre != cur);
      }
    }
    swap(group, new_group);
    cnt = group[a[n - 1]] + 1;
    step <<= 1;
  }
  return a;
}

template <typename T>
vector<int> suffix_array(const T &s, int char_bound) {
  return suffix_array((int) s.size(), s, char_bound);
}

template <typename T>
vector<int> build_lcp(int n, const T &s, const vector<int> &sa) {
  assert((int) sa.size() == n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[sa[i]] = i;
  }
  vector<int> lcp(max(n - 1, 0));
  int k = 0;
  for (int i = 0; i < n; i++) {
    k = max(k - 1, 0);
    if (pos[i] == n - 1) {
      k = 0;
    } else {
      int j = sa[pos[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
        k++;
      }
      lcp[pos[i]] = k;
    }
  }
  return lcp;
}

template <typename T>
vector<int> build_lcp(const T &s, const vector<int> &sa) {
  return build_lcp((int) s.size(), s, sa);
}

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

const int N = 1010;

int mv[N];
long long dp1[N], dp2[N];
long long* cur_dp = dp1;
long long* new_dp = dp2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  vector<int> sa = suffix_array(s, 256);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[sa[i]] = i;
  }
  vector<int> lcp = build_lcp(s, sa);
  SparseTable<int> st(lcp, [&](int i, int j) { return min(i, j); });
  auto GetLcp = [&](int i, int j) {
    if (i == j) {
      return n - i;
    }
    i = pos[i];
    j = pos[j];
    if (i > j) {
      swap(i, j);
    }
    return st.get(i, j - 1);
  };
  s += " ";
  auto Good = [&]() {
    cur_dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      cur_dp[i] = 0;
    }
    for (int step = 0; step < m; step++) {
      memset(new_dp + step + 1, 0, sizeof(long long) * (n - m + 1));
      for (int i = step; i <= n - m + step; i++) {
        new_dp[mv[i]] = min(k, new_dp[mv[i]] + cur_dp[i]);
      }
      for (int i = step + 1; i <= n - m + step; i++) {
        new_dp[i + 1] = min(k, new_dp[i + 1] + new_dp[i]);
      }
      swap(cur_dp, new_dp);
    }
    return (cur_dp[n] >= k);
  };
  string res = "";
  int from = 0, to = n - 1;
  while (true) {
    int sz = (int) res.size();
    vector<tuple<char, int, int>> segs;
    int beg = from;
    while (beg <= to) {
      char me = s[sa[beg] + sz];
      if (me == ' ') {
        beg += 1;
        continue;
      }
      int end = beg;
      while (end + 1 <= to) {
        char other = s[sa[end + 1] + sz];
        if (me != other) {
          break;
        }
        ++end;
      }
      segs.emplace_back(me, beg, end);
      beg = end + 1;
    }
    tuple<char, int, int> last = make_tuple(' ', -1, -1);
    for (auto& p : segs) {
      res += get<0>(p);
      int any = sa[get<1>(p)];
      for (int i = 0; i < n; i++) {
        int x = GetLcp(i, any);
        if (x >= sz + 1) {
          mv[i] = i + (sz + 1);
        } else {
          if (s[i + x] < res[x]) {
            mv[i] = n + 1;
          } else {
            mv[i] = i + x + 1;
          }
        }
      }
      res.pop_back();
      if (!Good()) {
        break;
      }
      last = p;
    }
    if (get<0>(last) == ' ') {
      break;
    }
    res += get<0>(last);
    from = get<1>(last);
    to = get<2>(last);
  }
  cout << res << '\n';
  return 0;
}