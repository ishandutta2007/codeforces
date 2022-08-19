/**
 *    author:  tourist
 *    created: 28.10.2018 19:37:40       
**/
#undef _GLIBCXX_DEBUG
#undef LOCAL

#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
  int len;
  cin >> len;
  string s;
  cin >> s;
  vector<int> sa = suffix_array(len, s, 256);
  vector<int> pos_in_sa(len);
  for (int i = 0; i < len; i++) {
    pos_in_sa[sa[i]] = i;
  }
  vector<int> lcp = build_lcp(len, s, sa);
  int max_log = 32 - __builtin_clz(len) + 1;
  vector<vector<int>> mins(max_log, vector<int>(len - 1));
  for (int i = 0; i < len - 1; i++) {
    mins[0][i] = lcp[i];
  }
  for (int j = 1; j < max_log; j++) {
    for (int i = 0; i <= len - 1 - (1 << j); i++) {
      mins[j][i] = min(mins[j - 1][i], mins[j - 1][i + (1 << (j - 1))]);
    }
  }
  vector<int> zeros(len + 1);
  for (int i = 1; i <= len; i++) {
    zeros[i] = 32 - __builtin_clz(i) - 1;
  }
  auto get_min = [&](int from, int to) {
    int lenn = to - from + 1;
    int lg = zeros[lenn];//32 - __builtin_clz(lenn) - 1;
    return min(mins[lg][from], mins[lg][to - (1 << lg) + 1]);
  };
  auto get_lcp = [&](int i, int j) {
    if (i == j) {
      return len - i;
    }
    int x = pos_in_sa[i];
    int y = pos_in_sa[j];
    if (x > y) {
      swap(x, y);
    }
    return get_min(x, y - 1);
  };
  int tt;
  cin >> tt;
  vector<int> from(tt), to(tt);
  vector<int> res(tt, 0);
  for (int i = 0; i < tt; i++) {
    cin >> from[i] >> to[i];
    from[i]--; to[i]--;
  }
  // check -1
  for (int i = 0; i < tt; i++) {
    if (to[i] - from[i] + 1 <= 26) {
      vector<int> used(26, 0);
      int ok = 1;
      for (int j = from[i]; j <= to[i]; j++) {
        int c = (int) (s[j] - 'a');
        if (used[c] == 1) {
          ok = 0;
          break;
        }
        used[c] = 1;
      }
      if (ok) {
        res[i] = -1;
      }
    }
  }
  // check 1
  vector<vector<int>> divs(len + 1);
  for (int i = 1; i <= len; i++) {
    for (int j = i + i; j <= len; j += i) {
      divs[j].push_back(i);
    }
  }
  for (int i = 0; i < tt; i++) {
    if (res[i] != 0) {
      continue;
    }
    int u = to[i] - from[i] + 1;
    for (int j : divs[u]) {
      if (get_lcp(from[i], from[i] + j) >= u - j) {
        res[i] = 1;
        break;
      }
    }
  }
  // check 2
  string rev_s(s.rbegin(), s.rend());
  vector<int> rev_sa = suffix_array(len, rev_s, 256);
  vector<int> pos_in_rev_sa(len);
  for (int i = 0; i < len; i++) {
    pos_in_rev_sa[rev_sa[i]] = i;
  }
  vector<int> rev_lcp = build_lcp(len, rev_s, rev_sa);
  vector<vector<int>> rev_mins(len - 1, vector<int>(max_log));
  for (int i = 0; i < len - 1; i++) {
    rev_mins[i][0] = rev_lcp[i];
  }
  for (int j = 1; j < max_log; j++) {
    for (int i = 0; i <= len - 1 - (1 << j); i++) {
      rev_mins[i][j] = min(rev_mins[i][j - 1], rev_mins[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto get_rev_min = [&](int fromm, int too) {
    int lenn = too - fromm + 1;
    int lg = 32 - __builtin_clz(lenn) - 1;
    return min(rev_mins[fromm][lg], rev_mins[too - (1 << lg) + 1][lg]);
  };
  auto get_rev_lcp = [&](int i, int j) {
    i = len - 1 - i;
    j = len - 1 - j;
    if (i == j) {
      return len - i;
    }
    int x = pos_in_rev_sa[i];
    int y = pos_in_rev_sa[j];
    if (x > y) {
      swap(x, y);
    }
    return get_rev_min(x, y - 1);
  };
  vector<int> best_repeat_end(len, len);
  vector<int> best_repeat_start(len, len);
  {
    dsu dd(len + 1);
    for (int k = 1; k <= len / 2; k++) {
      int i = 0;
      while (i + k + k <= len) {
        int cur = get_lcp(i, i + k);
        if (cur >= k) {
          int bound = i + (cur - k);
          while (true) {
            int j = dd.get(i);
            if (j > bound) {
              break;
            }
            best_repeat_end[j] = j + k + k - 1;
            dd.unite(j, j + 1);
          }
        }
        i += cur;
        i++;
        if (i + k + k > len) {
          break;
        }
        int u = get_rev_lcp(i + k - 1, i + k + k - 1);
        debug(k, i, u);
        if (u < k) {
          i += k - u;
        }
      }
    }
  }
  debug(best_repeat_end);
  {
    dsu dd(len + 1);
    for (int k = 1; k <= len / 2; k++) {
      int i = 0;
      while (i + k + k <= len) {
        int cur = get_rev_lcp(len - 1 - i, len - 1 - (i + k));
        if (cur >= k) {
          int bound = i + (cur - k);
          while (true) {
            int j = dd.get(i);
            if (j > bound) {
              break;
            }
            best_repeat_start[j] = j + k + k - 1;
            dd.unite(j, j + 1);
          }
        }
        i += cur;
        i++;
        if (i + k + k > len) {
          break;
        }
        int u = get_lcp(len - 1 - (i + k - 1), len - 1 - (i + k + k - 1));
        if (u < k) {
          i += k - u;
        }
      }
    }
    debug(best_repeat_start);
    reverse(best_repeat_start.begin(), best_repeat_start.end());
    for (int i = 0; i < len; i++) {
      best_repeat_start[i] = len - 1 - best_repeat_start[i];
    }
  }
  debug(best_repeat_start);
  for (int i = 0; i < tt; i++) {
    if (res[i] != 0) {
      continue;
    }
    if (best_repeat_start[to[i]] >= from[i]) {
      res[i] = 2;
    }
    if (best_repeat_end[from[i]] <= to[i]) {
      res[i] = 2;
    }
  }
  int SQRT = (int) (sqrt(len) + 1);
  for (int i = 0; i < tt; i++) {
    if (res[i] != 0) {
      continue;
    }
    for (int u = 1; u <= SQRT && u < to[i] - from[i] + 1; u++) {
      if (get_lcp(from[i], to[i] - u + 1) >= u) {
        res[i] = 2;
        break;
      }
    }
  }
  for (int i = 0; i < tt; i++) {
    if (res[i] != 0) {
      continue;
    }
    for (int j = max(0, pos_in_sa[from[i]] - SQRT); j <= min(len - 1, pos_in_sa[from[i]] + SQRT); j++) {
      if (sa[j] > from[i] && sa[j] <= to[i] - SQRT && get_lcp(from[i], sa[j]) >= to[i] - sa[j] + 1) {
        res[i] = 2;
        break;
      }
    }
  }
  // check 3
  debug(best_repeat_start);
  vector<int> max_best_repeat_start = best_repeat_start;
  for (int i = 1; i < len; i++) {
    max_best_repeat_start[i] = max(max_best_repeat_start[i], max_best_repeat_start[i - 1]);
  }
  for (int i = 0; i < tt; i++) {
    if (res[i] != 0) {
      continue;
    }
    if (max_best_repeat_start[to[i]] >= from[i]) {
      res[i] = 3;
    }
  }
  const int ALPHA = 26;
  vector<vector<int>> sum(len + 1);
  sum[0] = vector<int>(ALPHA, 0);
  for (int i = 0; i < len; i++) {
    sum[i + 1] = sum[i];
    int c = (int) (s[i] - 'a');
    sum[i + 1][c]++;
  }
  for (int i = 0; i < tt; i++) {
    if (res[i] != 0) {
      continue;
    }
    {
      int c = (int) (s[from[i]] - 'a');
      int u = sum[to[i] + 1][c] - sum[from[i] + 1][c];
      if (u > 0) {
        res[i] = 3;
      }
    }
    {
      int c = (int) (s[to[i]] - 'a');
      int u = sum[to[i]][c] - sum[from[i]][c];
      if (u > 0) {
        res[i] = 3;
      }
    }
  }
  // check 4
  for (int i = 0; i < tt; i++) {
    if (res[i] != 0) {
      continue;
    }
    res[i] = 4;
  }
  // output
  for (int i = 0; i < tt; i++) {
    cout << res[i] << '\n';
  }
  cerr << "time = " << clock() << " ms" << '\n';
  return 0;
}