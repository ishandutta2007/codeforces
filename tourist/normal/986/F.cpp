/**
 *    author:  tourist
 *    created: 29.05.2018 19:27:56       
**/
#include <bits/stdc++.h>

using namespace std;

long long mulmod(long long a, long long b, long long c) {
  long long sign = 1;
  if (a < 0) {
    a = -a;
    sign = -sign;
  }
  if (b < 0) {
    b = -b;
    sign = -sign;
  }
  a %= c;
  b %= c;
  long long res = 0;
  while (b > 0) {
    if (b & 1) {
      res = (res + a) % c;
    }
    a = (a + a) % c;
    b >>= 1;
  }
  if (sign == -1) {
    res = (-res) % c;
  }
  return res;
}

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T p = b / a;
  T g = extgcd(b - p * a, a, y, x);
  x -= p * y;
  return g;
}

template<typename T>
bool diophantine(T a, T b, T c, T &x, T &y, T &g) {
  if (a == 0 && b == 0) {
    if (c == 0) {
      x = y = g = 0;
      return true;
    }
    return false;
  }
  if (a == 0) {
    if (c % b == 0) {
      x = 0;
      y = c / b;
      g = abs(b);
      return true;
    }
    return false;
  }
  if (b == 0) {
    if (c % a == 0) {
      x = c / a;
      y = 0;
      g = abs(a);
      return true;
    }
    return false;
  }
  g = extgcd(a, b, x, y);
  if (c % g != 0) {
    return false;
  }
  T dx = c / a;
  c -= dx * a;
  T dy = c / b;
  c -= dy * b;
  x = dx + mulmod(x, c / g, b);
  y = dy + mulmod(y, c / g, a);
  g = abs(g);
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = (int) (sqrt(1e15) + 1e3);
  vector<bool> is_prime(MAX, true);
  for (int i = 2; i * i < MAX; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i < MAX; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  int sz = (int) primes.size();
  int tt;
  cin >> tt;
  vector<long long> ns(tt), ks(tt);
  map<long long,vector<int>> mapik;
  vector<int> res(tt, 0);
  for (int i = 0; i < tt; i++) {
    cin >> ns[i] >> ks[i];
    mapik[ks[i]].push_back(i);
  }
  for (auto &p : mapik) {
    long long k = p.first;
    vector<long long> d;
    {
      long long tmp = k;
      for (int it = 0; it < sz && (long long) primes[it] * primes[it] <= tmp; it++) {
        if (tmp % primes[it] == 0) {
          d.push_back(primes[it]);
          while (tmp % primes[it] == 0) {
            tmp /= primes[it];
          }
        }
      }
      if (tmp > 1) {
        d.push_back(tmp);
      }
    }
    if (d.size() == 0) {
      continue;
    }
    if (d.size() == 1) {
      for (int i : p.second) {
        res[i] = (ns[i] % d[0] == 0);
      }
      continue;
    }
    if (d.size() == 2) {
      for (int i : p.second) {
        long long x, y, g;
        if (diophantine(d[0], d[1], ns[i], x, y, g)) {
          if (x >= 0 && y < 0) {
            long long can_subtr = x / d[1];
            long long need_add = ((-y) + d[0] - 1) / d[0];
            if (can_subtr >= need_add) {
              y = 0;
            }
          }
          if (x < 0 && y >= 0) {
            long long can_subtr = y / d[0];
            long long need_add = ((-x) + d[1] - 1) / d[1];
            if (can_subtr >= need_add) {
              x = 0;
            }
          }
          res[i] = (x >= 0 && y >= 0);
        }
      }
      continue;
    }
    const long long inf = (long long) 2e18;
    vector<long long> dist(d[0], inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > s;
    dist[0] = 0;
    s.emplace(dist[0], 0);
    while (!s.empty()) {
      long long expected = s.top().first;
      int i = s.top().second;
      s.pop();
      if (dist[i] != expected) {
        continue;
      }
      for (int it = 1; it < (int) d.size(); it++) {
        int to = (int) ((i + d[it]) % d[0]);
        if (dist[i] + d[it] < dist[to]) {
          dist[to] = dist[i] + d[it];
          s.emplace(dist[to], to);
        }
      }
    }
    for (int i : p.second) {
      res[i] = (ns[i] >= dist[ns[i] % d[0]]);
    }
  }
  for (int i = 0; i < tt; i++) {
    cout << (res[i] ? "YES" : "NO") << '\n';
  }
  return 0;
}