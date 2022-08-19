/**
 *    author:  tourist
 *    created: 26.10.2019 13:01:17       
**/
#undef _GLIBCXX_DEBUG

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
  string foo;
  cin >> foo;
  vector<int> s(foo.size());
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    s[i] = (int) (foo[i] - 'a');
  }
  const int ALPHA = 26;
  vector<vector<int>> prev(n, vector<int>(ALPHA));
  for (int c = 0; c < ALPHA; c++) {
    prev[0][c] = -1;
  }
  for (int i = 1; i < n; i++) {
    prev[i] = prev[i - 1];
    prev[i][s[i - 1]] = i - 1;
  }
  vector<vector<int>> next(n, vector<int>(ALPHA));
  for (int c = 0; c < ALPHA; c++) {
    next[n - 1][c] = n;
  }
  for (int i = n - 2; i >= 0; i--) {
    next[i] = next[i + 1];
    next[i][s[i + 1]] = i + 1;
  }
  vector<vector<int>> prev_order(n, vector<int>(ALPHA));
  for (int i = 0; i < n; i++) {
    iota(prev_order[i].begin(), prev_order[i].end(), 0);
    sort(prev_order[i].begin(), prev_order[i].end(), [&](int x, int y) {
      return prev[i][x] > prev[i][y];
    });
  }
  vector<vector<int>> next_order(n, vector<int>(ALPHA));
  for (int i = 0; i < n; i++) {
    iota(next_order[i].begin(), next_order[i].end(), 0);
    sort(next_order[i].begin(), next_order[i].end(), [&](int x, int y) {
      return next[i][x] < next[i][y];
    });
  }
  auto Submask = [&](int A, int B) {
    return ((A & B) == A);
  };
  vector<long long> res(n, n - 1);
  vector<int> subset(n);
  vector<int> L(n), R(n);
  for (int i = 0; i < n; i++) {
    subset[i] = (1 << s[i]);
    L[i] = i;
    R[i] = i;
  }
  int real_alpha = 0;
  for (int i = 0; i < n; i++) {
    real_alpha |= subset[i];
  }
  real_alpha = __builtin_popcount(real_alpha);
  const int LOG = 19;
  vector<vector<int>> jumpL(n, vector<int>(LOG, 0));
  vector<vector<int>> jumpR(n, vector<int>(LOG, n - 1));
  vector<int> cntJumpL(n);
  vector<int> cntJumpR(n);
  vector<vector<long long>> sumJumpL(n, vector<long long>(LOG, 0));
  vector<vector<long long>> sumJumpR(n, vector<long long>(LOG, 0));
  vector<int> prev_subset(n, 0);
  vector<int> next_subset(n, 0);
  for (int pc = 1; pc <= real_alpha; pc++) {
    for (int i = 0; i < n; i++) {
      if (prev[i][prev_order[i][pc - 1]] != -1) {
        prev_subset[i] |= (1 << prev_order[i][pc - 1]);
      }
      if (next[i][next_order[i][pc - 1]] != n) {
        next_subset[i] |= (1 << next_order[i][pc - 1]);
      }
    }
    cntJumpL[0] = n;
    for (int i = 1; i < n; i++) {
      jumpL[i][0] = max(0, prev[i][prev_order[i][pc - 1]]);
      if (jumpL[i][0] == 0) {
        cntJumpL[i] = n;
      } else {
        if (!Submask(prev_subset[jumpL[i][0]], prev_subset[i])) {
          cntJumpL[i] = 1;
        } else {
          cntJumpL[i] = cntJumpL[jumpL[i][0]] + 1;
        }
      }
      sumJumpL[i][0] = jumpL[i][0];
    }
    cntJumpR[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
      jumpR[i][0] = min(n - 1, next[i][next_order[i][pc - 1]]);
      if (jumpR[i][0] == n - 1) {
        cntJumpR[i] = n;
      } else {
        if (!Submask(next_subset[jumpR[i][0]], next_subset[i])) {
          cntJumpR[i] = 1;
        } else {
          cntJumpR[i] = cntJumpR[jumpR[i][0]] + 1;
        }
      }
      sumJumpR[i][0] = n - 1 - jumpR[i][0];
    }
//    debug(cntJumpR);
//    debug(next_subset);
    vector<int> jumps(n);
    int max_jumps = 0;
    for (int i = 0; i < n; i++) {
      if (__builtin_popcount(subset[i]) != pc) {
        continue;
      }
      int cntL = 0;
      int cntR = 0;
      if (Submask(prev_subset[L[i]], subset[i]) || L[i] == 0) {
        cntL = max(0, cntJumpL[L[i]]);
      }
      if (Submask(next_subset[R[i]], subset[i]) || R[i] == n - 1) {
        cntR = max(0, cntJumpR[R[i]]);
      }
      jumps[i] = (pc == real_alpha ? max(cntL, cntR) : min(cntL, cntR));
      max_jumps = max(max_jumps, jumps[i]);
    }
    int CUR_LOG = 0;
    while ((1 << CUR_LOG) <= max_jumps) {
      CUR_LOG += 1;
    }
    for (int j = 1; j < CUR_LOG; j++) {
      for (int i = 0; i < n; i++) {
        jumpL[i][j] = jumpL[jumpL[i][j - 1]][j - 1];
        sumJumpL[i][j] = sumJumpL[i][j - 1] + sumJumpL[jumpL[i][j - 1]][j - 1];
        jumpR[i][j] = jumpR[jumpR[i][j - 1]][j - 1];
        sumJumpR[i][j] = sumJumpR[i][j - 1] + sumJumpR[jumpR[i][j - 1]][j - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      if (__builtin_popcount(subset[i]) != pc) {
        continue;
      }
//      debug(pc, subset[i], i, L[i], R[i], cntL, cntR, jumps);
      for (int j = 0; j < CUR_LOG; j++) {
        if (jumps[i] & (1 << j)) {
          res[i] += sumJumpL[L[i]][j];
          L[i] = jumpL[L[i]][j];
          res[i] += sumJumpR[R[i]][j];
          R[i] = jumpR[R[i]][j];
        }
      }
      int newL = L[i];
      int newR = R[i];
      for (int c = 0; c < ALPHA; c++) {
        if (subset[i] & (1 << c)) {
          newL = min(newL, prev[L[i]][c]);
          newR = max(newR, next[R[i]][c]);
        }
      }
      newL = max(newL, 0);
      newR = min(newR, n - 1);
      L[i] = newL;
      R[i] = newR;
      res[i] += newL + (n - 1 - newR);
      int new_subset = 0;
      for (int c = 0; c < ALPHA; c++) {
        if (s[L[i]] == c || next[L[i]][c] <= R[i]) {
          new_subset |= (1 << c);
        }
      }
//      debug(pc, i, L[i], R[i], subset[i], new_subset);
      assert(pc == real_alpha || __builtin_popcount(new_subset) > pc);
      subset[i] = new_subset;
    }
  }
//  debug(subset, L, R, res);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += res[i];
  }
  cout << ans << '\n';
  cerr << "time = " << clock() << " ms" << '\n';
  return 0;
}