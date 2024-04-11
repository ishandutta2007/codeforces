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
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      int val_i = i - 2 * a[i];
      int val_j = j - 2 * a[j];
      if (val_i != val_j) {
        return val_i > val_j;
      } else {
        return a[i] > a[j];
      }
    });
    long long inv = 0;
    fenwick<int> fenw(n);
    for (int i = n - 1; i >= 0; i--) {
      inv += fenw.get(a[i]);
      fenw.modify(a[i], 1);
    }
    vector<long long> ans(n);
    {
      fenwick<int> pos(n);
      fenwick<int> val(n);
      fenwick<int> L(n);
      for (int i = 0; i < n; i++) {
        L.modify(i, 1);
      }
      long long tot = inv;
      long long c = 0;
      for (int id = 0; id < n; id++) {
        int i = order[id];
        int b = a[i] - val.get(a[i]);
        int p = i - pos.get(i);
        tot -= (p - 2 * b);
        L.modify(a[i], -1);
        tot -= L.get(a[i]);
        ans[id] += tot;
        pos.modify(i, 1);
        val.modify(a[i], 1);
      }
    }
    {
      reverse(a.begin(), a.end());
      for (int i = 0; i < n; i++) {
        a[i] = n - a[i] - 1;
      }
      fenwick<int> pos(n);
      fenwick<int> val(n);
      long long tot = inv;
      fenwick<int> L(n);
      for (int i = 0; i < n; i++) {
        L.modify(i, 1);
      }
      long long c = 0;
      for (int id = n - 1; id >= 0; id--) {
        int i = n - order[id] - 1;
        int b = a[i] - val.get(a[i]);
        int p = i - pos.get(i);
        ans[id] += tot;
        L.modify(a[i], -1);
        tot -= L.get(a[i]);
        tot -= (p - 2 * b);
        pos.modify(i, 1);
        val.modify(a[i], 1);
      }
    }
    {
      reverse(a.begin(), a.end());
      for (int i = 0; i < n; i++) {
        a[i] = n - a[i] - 1;
      }
      fenwick<int> L(n);
      fenwick<int> R(n);
      for (int i = 0; i < n; i++) {
        R.modify(i, 1);
      }
      long long qq = 0;
      for (int id = 0; id < n; id++) {
        int i = order[id];
        R.modify(a[i], -1);
        qq += R.get(a[i]);
        qq -= id - L.get(a[i]);
        ans[id] += qq; 
        L.modify(a[i], 1);
      }
    }
    ans[n - 1] = inv;
    cout << inv << " ";
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }                                                                    
  return 0;
}