#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
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
 
#ifdef PC
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

pair<int, vector<int>> solve(int n, vector<int> &a, vector<int> &order) {
  vector<int> par(n, -1);
  vector<bool> used(n);
  int cnt = 0;
  for (int i : order) {
    if (a[i] != i && !used[a[i]]) {
      used[a[i]] = true;
      par[i] = a[i];
      cnt++;
    }
  }
  if (cnt == n - 1) {
    int id = -1, to = -1;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        to = i;
      }
      if (par[i] == -1) {
        id = i;
      }
    }
    if (id != to) {
      par[id] = to;
    } else {
      int other = -1;
      for (int i = 0; i < n; i++) {
        if (i != id) {
          other = i;
          break;
        }
      }
      par[id] = par[other];
      par[other] = to;
    }
  } else {
    vector<int> ids, tos;
    for (int i = 0; i < n; i++) {
      if (par[i] == -1) {
        ids.pb(i);
      }
      if (!used[i]) {
        tos.pb(i);
      }
    }
    if (!ids.empty()) {
      vector<int> eq;
      for (int i = 0; i < SZ(ids); i++) {
        par[ids[i]] = tos[i];
        if (ids[i] == tos[i]) {
          eq.pb(ids[i]);
        }
      }
      if (SZ(eq) == 1) {
        for (int i = 0; i < SZ(ids); i++) {
          if (ids[i] != eq[0]) {
            debug(i, ids[i], tos[i]);
            par[eq[0]] = tos[i];
            par[ids[i]] = eq[0];
            break;
          }
        }
      } else {
        for (int i = 0; i < SZ(eq); i++) {
          par[eq[i]] = eq[(i + 1) % SZ(eq)];
        }
      }
    }
  }
  int cnt_good = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == par[i]) {
      cnt_good++;
    }
    assert(i != par[i]);
  }
  return {cnt_good, par};
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      x--;
    }
    vector<int> order1, order2;
    for (int i = 0; i < n; i++) {
      order1.pb(i);
    }
    order2 = order1;
    reverse(all(order2));
    auto ans1 = solve(n, a, order1), ans2 = solve(n, a, order2);
    if (ans1.F < ans2.F) {
      swap(ans1, ans2);
    }
    cout << ans1.F << '\n';
    for (auto it : ans1.S) {
      cout << it + 1 << ' ';
    } 
    cout << '\n';
  }
}