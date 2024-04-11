/**
 *    author:  wxhtzdy
 *    created: 16.08.2022 18:05:35
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
    int k;
    cin >> k;
    vector<long long> c(k);
    for (int i = 0; i < k; i++) {
      cin >> c[i];
    }
    sort(c.begin(), c.end());
    long long sum = accumulate(c.begin(), c.end(), 0LL);
    if (sum <= 2) {
      if (k == 1) {
        cout << (sum == 1 ? "YES" : "NO") << '\n';
      } else {
        cout << "YES" << '\n';
      }
      continue;
    }                        
    sum -= 2;            
    vector<int> fib(2, 1);
    while (true) {
      int a = fib.rbegin()[1];
      int b = fib.rbegin()[0];
      int x = a + b;
      if (sum < x || c[k - 1] < x) {
        break;
      }
      sum -= x;
      fib.push_back(x);
    }
    if (k == 1) {
      cout << "NO" << '\n';
      continue;
    } 
    multiset<pair<int, int>> st;
    for (int i = 0; i < k; i++) {
      st.emplace(c[i], i);
    }      
    int lst = -1;
    for (int i = (int) fib.size() - 1; i >= 0; i--) {
      auto it = prev(st.end());
      if (it->second != lst && it->first >= fib[i]) {
        lst = it->second;
        st.erase(st.find({c[lst], lst}));
        c[lst] -= fib[i];
        st.emplace(c[lst], lst);
      } else {
        if (it != st.begin()) {
          it = prev(it);
          if (it->first >= fib[i]) {
            lst = it->second;
            st.erase(st.find({c[lst], lst}));
            c[lst] -= fib[i];
            st.emplace(c[lst], lst);
          }
        }
      }
    }
    cout << (*max_element(c.begin(), c.end()) == 0 && *min_element(c.begin(), c.end()) == 0 ? "YES" : "NO") << '\n'; 
  }                                                                  
  return 0;
}