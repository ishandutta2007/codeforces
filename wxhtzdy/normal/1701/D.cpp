/**
 *    author:  wxhtzdy
 *    created: 08.07.2022 17:44:54
**/
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;                    
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      if (b[i] == 0) {
        l[i] = i + 2;
        r[i] = n; 
      } else {
        l[i] = (i + 1) / b[i];
        r[i] = (i + 1) / (b[i] + 1) + 1;
        r[i] = min(r[i], i + 1);
        l[i] = min(l[i], i + 1);
        if (l[i] > r[i]) {
          swap(l[i], r[i]);
        }
        while ((i + 1) / l[i] > b[i]) {
          l[i]--;
        }
        while (l[i] > 1 && (i + 1) / (l[i] - 1) == b[i]) {
          l[i] -= 1;
        }         
        while ((i + 1) / r[i] < b[i]) {
          r[i]++;
        }
        while ((i + 1) / (r[i] + 1) == b[i]) {
          r[i]++;
        }
      }
    }
    debug(l);
    debug(r);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      if (r[i] != r[j]) {
        return r[i] < r[j];
      }
      return l[i] < l[j];
    });
    vector<vector<pair<int, int>>> qs(n + 1);
    for (int i = 0; i < n; i++) {
      qs[l[i]].emplace_back(r[i], i);
    }
    vector<int> ans(n);
    set<pair<int, int>> st;   
    for (int i = 1; i <= n; i++) {
      for (auto& p : qs[i]) {
        st.insert(p);
      }
      auto it = st.begin();
      int id = it->second;
      ans[id] = i;
      st.erase(it);
    }
    for (int i = 0; i < n; i++) {
      assert((i + 1) / ans[i] == b[i]);
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }                                                                  
  return 0;
}