/**
 *    author:  tourist
 *    created: 24.09.2020 21:15:17       
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

const int inf = (int) 1e9;
const int N = 81;

int dp[N][N * N][N];
int new_dp[N][N * N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // A = 0 0 0 0 1 1 1 1 0 1 1 0
  // B = 1 0 0 1 0 1 0 0 1 0 1 1
  // posA = [0, 1, 2, 3, 8, 11] (positions of zeroes in A)
  // posB = [1, 2, 4, 6, 7, 9]
  // number of exchanges required to transform A into B == sum(abs(posA[i] - posB[i]))

  // dp[i][zeroes][total_distance][last_consecutive_zeroes] -> # of pairs of zeroes without 1's in between
  // O(n^5)?

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> posA;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      posA.push_back(i);
    }
  }
  int cnt0 = (int) posA.size();
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int z = 0; z <= i + 1; z++) {
      for (int d = 0; d <= min((i + 1) * (n - 1), n * (n - 1) / 2); d++) {
        for (int c = 0; c <= i + 1; c++) {
          new_dp[z][d][c] = inf;
        }
      }
    }
    for (int z = 0; z <= i; z++) {
      for (int d = 0; d <= min(i * (n - 1), n * (n - 1) / 2); d++) {
        for (int c = 0; c <= i; c++) {
          if (dp[z][d][c] == inf) {
            continue;
          }
          if (z < cnt0) { // put 0
            new_dp[z + 1][d + abs(posA[z] - i)][c + 1] = min(new_dp[z + 1][d + abs(posA[z] - i)][c + 1], dp[z][d][c] + c);
          }

          { // put 1
            new_dp[z][d][0] = min(new_dp[z][d][0], dp[z][d][c]);
          }
        }
      }
    }
    for (int z = 0; z <= i + 1; z++) {
      for (int d = 0; d <= min((i + 1) * (n - 1), n * (n - 1) / 2); d++) {
        for (int c = 0; c <= i + 1; c++) {
          dp[z][d][c] = new_dp[z][d][c];
        }
      }
    }
  }
  vector<int> mn(n * (n - 1) / 2 + 1, inf);
  for (int total_distance = 0; total_distance <= n * (n - 1) / 2; total_distance++) {
    for (int last_consecutive_zeroes = 0; last_consecutive_zeroes <= cnt0; last_consecutive_zeroes++) {
      mn[total_distance] = min(mn[total_distance], dp[cnt0][total_distance][last_consecutive_zeroes]);
    }
  }
  for (int i = 1; i <= n * (n - 1) / 2; i++) {
    mn[i] = min(mn[i], mn[i - 1]);
  }
  int total_pairs = cnt0 * (cnt0 - 1) / 2;
  for (int i = 0; i <= n * (n - 1) / 2; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << total_pairs - mn[i];
  }
  cout << '\n';
  debug(clock());
  return 0;
}