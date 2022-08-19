/**
 *    author:  tourist
 *    created: 03.03.2020 18:53:02       
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
  int n, m;
  cin >> n >> m;
  vector<int> L(n), R(n);
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
  }
  vector<int> val(m, -1);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    --x;
    val[x] = y;
  }
  long long t;
  cin >> t;
  long long sL = 0, sR = 0;
  for (int i = 0; i < n; i++) {
    sL += L[i];
    sR += R[i];
  }
  if (t < sL || t > sR) {
    cout << "-1 -1" << '\n';
    return 0;
  }
  vector<vector<int>> at(m + 1);
  for (int i = 0; i < n; i++) {
    at[L[i]].push_back(i);
  }
  long long cur = sL;
  set<pair<int, int>> s;
  for (int i = 0; i <= m; i++) {
    for (int j : at[i]) {
      s.emplace(R[j], j);
    }
    while (!s.empty() && s.begin()->first == i) {
      L[s.begin()->second] = i;
      s.erase(s.begin());
    }
    while ((long long) s.size() > t - cur) {
      L[s.begin()->second] = i;
      s.erase(s.begin());
    }
    cur += (long long) s.size();
  }
  assert(cur == t);
  assert(s.empty());
  vector<long long> maxp(m);
  for (int x : L) {
    maxp[0] += 1;
    if (x < m) {
      maxp[x] -= 1;
    }
  }
  long long aux = 0;
  long long delta = 0;
  for (int i = 0; i < m; i++) {
    delta += maxp[i];
    aux += delta;
    maxp[i] = aux;
  }
  vector<int> a = val;
  auto Test = [&]() {
    for (int i = 0; i < m - 1; i++) {
      if (a[i] != -1 && a[i + 1] != -1 && a[i] < a[i + 1]) {
        return false;
      }
    }
    vector<tuple<int, int, int, int>> segs;
    {
      int beg = 0;
      cur = 0;
      while (beg < m) {
        if (a[beg] != -1) {
          cur += a[beg];
          ++beg;
          continue;
        }
        int end = beg;
        while (end + 1 < m && a[end + 1] == -1) {
          ++end;
        }
        int low = (end == m - 1 ? 0 : a[end + 1]);
        int high = (beg == 0 ? n : a[beg - 1]);
        if (low > high) {
          return false;
        }
        cur += (long long) low * (end - beg + 1);
        segs.emplace_back(beg, end, low, high);
        beg = end + 1;
      }
    }
    if (cur > t) {
      return false;
    }
    for (int it = (int) segs.size() - 1; it >= 0; it--) {
      auto& seg = segs[it];
      int beg = get<0>(seg);
      int end = get<1>(seg);
      int low = get<2>(seg);
      int high = get<3>(seg);
      long long add = (long long) (end - beg + 1) * (high - low);
      if (cur + add <= t) {
        for (int i = beg; i <= end; i++) {
          a[i] = high;
        }
        cur += add;
      } else {
        long long to_all = (t - cur) / (end - beg + 1);
        for (int i = beg; i <= end; i++) {
          a[i] = (int) (low + to_all);
        }
        cur += to_all * (end - beg + 1);
        for (int i = beg; i < beg + (t - cur); i++) {
          a[i] += 1;
        }
        cur = t;
      }
    }
    if (cur != t) {
      return false;
    }
    aux = 0;
    for (int i = 0; i < m; i++) {
      aux += a[i];
      if (aux > maxp[i]) {
        return false;
      }
    }
    return true;
  };
  if (!Test()) {
    cout << "-1 -1" << '\n';
    return 0;
  }
  int first = a[0];
  int low = 1, high = m;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    a = val;
    if (a[mid - 1] != -1 && a[mid - 1] != first) {
      high = mid - 1;
      continue;
    }
    a[mid - 1] = first;
    if (Test()) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  int people = low;
  low = first, high = n;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    a = val;
    if (a[people - 1] != -1 && a[people - 1] != mid) {
      high = mid - 1;
      continue;
    }
    a[people - 1] = mid;
    if (Test()) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  int score = low;
  cout << people << " " << score << '\n';
  return 0;
}