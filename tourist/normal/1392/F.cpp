/**
 *    author:  tourist
 *    created: 16.08.2020 18:00:14       
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
  vector<long long> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<long long> d(n);
  for (int i = 0; i < n - 1; i++) {
    d[i] = h[i + 1] - h[i];
  }
  vector<int> zeros;
  for (int i = 0; i < n - 1; i++) {
    while (true) {
//      debug(i, d);
      if (d[i] <= 1) {
        break;
      }
      if (zeros.empty()) {
        if (d[i] >= i + 2) {
          long long cycles = d[i] / (i + 2);
          d[i] -= cycles * (i + 2);
          d[i + 1] += cycles * (i + 1);
          continue;
        }
        if (d[i] >= 2) {
          d[0] = 0;
          zeros.push_back(0);
          d[i] -= 1;
          d[i + 1] += 1;
        }
        continue;
      }
      int pos = zeros.back();
      int steps = i - pos;
      if (d[i] - 1 >= steps) {
        zeros.pop_back();
        d[pos] = 1;
        d[i] -= steps + 1;
        d[i + 1] += steps;
        continue;
      }
      d[zeros.back()] = 1;
      zeros.back() += (int) (d[i] - 1);
      d[zeros.back()] = 0;
      d[i + 1] += d[i] - 1;
      d[i] = 1;
    }
    if (d[i] == 0) {
      zeros.push_back(i);
    }
  }
  long long z = h.back();
  for (int i = n - 1; i >= 0; i--) {
    z -= d[i];
    h[i] = z;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << h[i];
  }
  cout << '\n';
  return 0;
}