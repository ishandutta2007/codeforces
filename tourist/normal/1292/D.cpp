/**
 *    author:  tourist
 *    created: 19.01.2020 16:49:43       
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
  const int MAX = 5010;
  vector<int> cnt(MAX);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
  }
  vector<int> is_prime(MAX, 1);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < MAX; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < MAX; j += i) {
        is_prime[j] = 0;
      }
    }
  }
  vector<int> cur(MAX, 0);
  vector<map<int, int>> trie(1);
  vector<int> at(1);
  long long add = 0;
  for (int i = 0; i < MAX; i++) {
    int tmp = i;
    for (int j = 2; j * j <= tmp; j++) {
      while (tmp % j == 0) {
        cur[j] += 1;
        tmp /= j;
      }
    }
    if (tmp > 1) {
      cur[tmp] += 1;
    }
    int t = 0;
    for (int j = MAX - 1; j >= 2; j--) {
      if (is_prime[j]) {
        add += (long long) cur[j] * cnt[i];
        auto it = trie[t].find(cur[j]);
        if (it == trie[t].end()) {
          trie[t][cur[j]] = (int) trie.size();
          t = (int) trie.size();
          trie.emplace_back();
          at.push_back(0);
        } else {
          t = it->second;
        }
        at[t] += cnt[i];
      }
    }
  }
  debug(add);
  long long ans = 0;
  function<void(int, long long)> Dfs = [&](int t, long long s) {
    ans = max(ans, s);
    int num = 0;
    for (auto& p : trie[t]) {
      num += at[p.second];
    }
    long long save = 0;
    for (auto& p : trie[t]) {
      int c = p.first;
      int to = p.second;
      Dfs(to, s + save + 2LL * num * c - (long long) c * n);
      num -= at[to];
      save += 2LL * at[to] * c;
    }
  };
  Dfs(0, 0);
  cout << add - ans << '\n';
  return 0;
}