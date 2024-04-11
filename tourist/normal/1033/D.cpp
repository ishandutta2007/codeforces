/**
 *    author:  tourist
 *    created: 07.10.2018 20:17:56       
**/
#include <bits/stdc++.h>

using namespace std;

long long my_sqrt(long long x) {
  assert(x > 0);
  long long y = (long long) (sqrtl((long double) x) + 0.5);
  while (y * y < x) {
    y++;
  }
  while (y * y > x) {
    y--;
  }
  if (y * y == x) {
    return y;
  }
  return -1;
}

long long my_crt(long long x) {
  assert(x > 0);
  long long y = (long long) (powl((long double) x, 1.0 / 3.0) + 0.5);
  while (y * y * y < x) {
    y++;
  }
  while (y * y * y > x) {
    y--;
  }
  if (y * y * y == x) {
    return y;
  }
  return -1;
}

long long gcd(long long a, long long b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<long long,int> mp;
  vector<long long> z;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    long long d = my_crt(a);
    if (d != -1) {
      mp[d] += 3;
      continue;
    }
    long long b = my_sqrt(a);
    if (b != -1) {
      long long c = my_sqrt(b);
      if (c != -1) {
        mp[c] += 4;
      } else {
        mp[b] += 2;
      }
    } else {
      z.push_back(a);
    }
  }
  int nz = (int) z.size();
  for (int i = 0; i < nz; i++) {
    for (int j = i + 1; j < nz; j++) {
      if (z[i] != z[j]) {
        long long x = gcd(z[i], z[j]);
        if (x > 1) {
          mp[x] = mp[x];
        }
      }
    }
  }
  vector<long long> cand;
  for (auto &p : mp) {
    cand.push_back(p.first);
  }
  for (int i = 0; i < nz; i++) {
    int found = 0;
    for (long long x : cand) {
      if (z[i] % x == 0) {
        mp[x]++;
        mp[z[i] / x]++;
        found = 1;
        break;
      }
    }
    if (!found) {
      mp[z[i]]--;
    }
  }
  const int md = 998244353;
  int ans = 1;
  for (auto &p : mp) {
    if (p.second > 0) {
      ans = (int) (((long long) ans * (1 + p.second)) % md);
    } else {
      ans = (int) (((long long) ans * (1 - p.second)) % md);
      ans = (int) (((long long) ans * (1 - p.second)) % md);
    }
  }
  cout << ans << '\n';
  return 0;
}