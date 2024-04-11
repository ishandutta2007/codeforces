/**
 *    author:  tourist
 *    created: 09.09.2020 21:45:18       
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
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<vector<int>> g(n);
  for (int rot = 0; rot < 2; rot++) {
    auto Add = [&](int i, int j) {
      g[i].push_back(j);
//      debug(rot, i, j);
    };
    // max(hi+1,...,hj-1) < min(hi,hj)
    vector<int> st;
    // h[st[0]] > h[st[1]] > ... > h[st.back()]
    for (int i = 0; i < n; i++) {
      while (!st.empty() && h[st.back()] < h[i]) {
        Add(st.back(), i);
        st.pop_back();
      }
      if (!st.empty()) {
        Add(st.back(), i);
        if (h[st.back()] == h[i]) {
          st.pop_back();
        }
      }
      st.push_back(i);
    }
    for (int i = 0; i < n; i++) {
      h[i] = -h[i];
    }
  }
  vector<int> dist(n, -1);
  vector<int> que(1, 0);
  dist[0] = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    for (int j : g[que[b]]) {
      if (dist[j] == -1) {
        que.push_back(j);
        dist[j] = dist[que[b]] + 1;
      }
    }
  }
  cout << dist[n - 1] << '\n';
  return 0;
}