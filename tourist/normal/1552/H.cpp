/**
 *    author:  tourist
 *    created: 25.07.2021 18:42:59       
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
  const int N = 200;
  auto Ask = [&](int col) {
    assert(1 <= col && col <= N);
    vector<pair<int, int>> q;
    for (int x = 1; x <= N; x++) {
      for (int y = col; y <= N; y += col) {
        q.emplace_back(x, y);
      }
    }
    cout << "? " << q.size() << endl;
    for (int i = 0; i < (int) q.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << q[i].first << " " << q[i].second;
    }
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
  };
  int area = Ask(1);
  vector<pair<int, int>> fs;
  for (int h = 2; h <= N; h++) {
    for (int w = 2; w <= N; w++) {
      if (h * w == area) {
        fs.emplace_back(h, w);
      }
    }
  }
  function<bool(vector<pair<int, int>>, int)> Solve = [&](vector<pair<int, int>> a, int rm) {
    int n = (int) a.size();
    if (n <= 1) {
      return true;
    }
    if (rm == 0) {
      return false;
    }
    for (int i = 0; i < n; i++) {
      int step = a[i].second;
      map<int, vector<pair<int, int>>> mp;
      for (int j = 0; j < (int) a.size(); j++) {
        int h = a[j].first;
        int w = a[j].second;
        int cnt = (w / step) * h;
        mp[cnt].push_back(a[j]);
        if (w % step != 0) {
          cnt += h;
          mp[cnt].push_back(a[j]);
        }
      }
      int cc = 0;
      for (auto& z : mp) {
        if ((int) z.second.size() == n) {
          cc = -1;
          break;
        }
      }
      if (cc == -1) {
        continue;
      }
      bool ok = true;
      for (auto& z : mp) {
        if (!Solve(z.second, rm - 1)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        return true;
      }
    }
    return false;
  };
  int cc = 4;
  for (int cur = 0; cur <= 3; cur++) {
    if (Solve(fs, cur)) {
      cc = cur;
      break;
    }
  }
  assert(cc != 4);
  auto a = fs;
  int rm = cc;
  while (a.size() > 1) {
    int n = (int) a.size();
    bool found = false;
    for (int i = 0; i < n; i++) {
      int step = a[i].second;
      map<int, vector<pair<int, int>>> mp;
      for (int j = 0; j < (int) a.size(); j++) {
        int h = a[j].first;
        int w = a[j].second;
        int cnt = (w / step) * h;
        mp[cnt].push_back(a[j]);
        if (w % step != 0) {
          cnt += h;
          mp[cnt].push_back(a[j]);
        }
      }
      int cc = 0;
      for (auto& z : mp) {
        if ((int) z.second.size() == n) {
          cc = -1;
          break;
        }
      }
      if (cc == -1) {
        continue;
      }
      bool ok = true;
      for (auto& z : mp) {
        if (!Solve(z.second, rm - 1)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        int got = Ask(step);
        a = mp[got];
        found = true;
        break;
      }
    }
    assert(found);
    rm -= 1;
  }
  assert(a.size() == 1);
  cout << "! " << 2 * (a[0].first - 1 + a[0].second - 1) << endl;
  return 0;
}