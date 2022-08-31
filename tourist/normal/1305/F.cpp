/**
 *    author:  tourist
 *    created: 03.03.2020 18:07:37       
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
  auto start = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const long long inf = (long long) 1e18;
  set<long long> tested;
  long long ans = inf;
  auto Test = [&](long long x) {
    if (tested.find(x) != tested.end()) {
      return inf;
    }
    tested.insert(x);
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < x) {
        cur += x - a[i];
      } else {
        long long r = a[i] % x;
        cur += min(r, x - r);
      }
    }
    ans = min(ans, cur);
    return cur;
  };
  Test(2);
  const int MAX = (int) 1e6 + 10;
  vector<bool> prime(MAX, true);
  for (int i = 2; i * i < MAX; i++) {
    if (prime[i]) {
      for (int j = i * i; j < MAX; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<int> p;
  for (int i = 2; i < MAX; i++) {
    if (prime[i]) {
      p.push_back(i);
    }
  }
  auto TestDiv = [&](long long x) {
    for (int i = 0; i < (int) p.size() && (long long) p[i] * p[i] <= x; i++) {
      if (x % p[i] == 0) {
        while (x % p[i] == 0) {
          x /= p[i];
        }
        Test(p[i]);
      }
    }
    if (x > 1) {
      Test(x);
    }
  };
  double q = 1.0 / CLOCKS_PER_SEC;
  const double TL = 1.5;
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  while ((clock() - start) * q < TL) {
    int i, j;
    do {
      i = rng() % n;
      j = rng() % n;
    } while (i == j);
    for (int di = -1; di <= 1; di++) {
      if (a[i] + di == 0) {
        continue;
      }
      for (int dj = -1; dj <= 1; dj++) {
        if (a[j] + dj == 0) {
          continue;
        }
        long long g = __gcd(a[i] + di, a[j] + dj);
        TestDiv(g);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}