/**
 *    author:  tourist
 *    created: 04.01.2019 19:20:03       
**/
#undef _GLIBCXX_DEBUG

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 100010;
  vector<int> pre(1, 0);
  for (int i = 1; (int) pre.size() < MAX; i++) {
    for (int j = 0; j < i + 1; j++) {
      pre.push_back(i);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
      pos[p[i]] = i;
    }
    vector<int> alive(n, 1);
    vector<vector<int>> res;
    vector<int> dp(n);
    vector<int> pr(n);
    int left = n;
    while (left > 0) {
      int found = 0;
      for (int rot = 0; rot < 2; rot++) {
        vector<vector<int>> seq;
        vector<int> u;
        for (int i = 0; i < n; i++) {
          if (!alive[i]) {
            continue;
          }
          int x = p[i];
          auto it = (rot == 0 ? lower_bound(u.begin(), u.end(), x, less<int>()) : lower_bound(u.begin(), u.end(), x, greater<int>()));
          dp[i] = (int) (it - u.begin()) + 1;
          pr[i] = (it == u.begin() ? -1 : u[dp[i] - 2]);
          if (it == u.end()) {
            seq.emplace_back(1, x);
            u.push_back(x);
          } else {
            seq[(int) (it - u.begin())].push_back(x);
            *it = x;
          }
        }
        if (pre[left - (int) u.size()] + 1 <= pre[left]) {
          found = 1;
          vector<int> who;
          for (int i = 0; i < n; i++) {
            if (alive[i] && dp[i] == (int) u.size()) {
              int j = i;
              while (true) {
                who.push_back(p[j]);
                if (pr[j] == -1) {
                  break;
                }
                j = pos[pr[j]];
              }
              reverse(who.begin(), who.end());
              assert((int) who.size() == (int) u.size());
              break;
            }
          }
          res.push_back(who);
          for (int x : who) {
            alive[pos[x]] = 0;
            left--;
          }
          continue;
        }
        vector<int> order(u.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
          return (seq[i].size() > seq[j].size());
        });
//        debug(seq);
        int sum = 0;
        for (int i = 0; i < (int) u.size(); i++) {
          sum += (int) seq[order[i]].size();
          if (pre[left - sum] + (i + 1) <= pre[left]) {
            found = 1;
            for (int j = 0; j <= i; j++) {
              res.push_back(seq[order[j]]);
              for (int x : seq[order[j]]) {
                alive[pos[x]] = 0;
                left--;
              }
            }
            break;
          }
        }
        if (found) {
          break;
        }
      }
      if (!found) debug(p);
      assert(found);
    }
    cout << (int) res.size() << '\n';
    for (auto& v : res) {
      cout << (int) v.size();
      for (int i : v) {
        cout << " " << i + 1;
      }
      cout << '\n';
    }
  }
  return 0;
}