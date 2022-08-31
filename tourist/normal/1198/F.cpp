/**
 *    author:  tourist
 *    created: 30.07.2019 18:14:20       
**/
#include <bits/stdc++.h>

using namespace std;

namespace factorizer {

vector<int> least = {0, 1};
vector<int> primes;
int precalculated = 1;

void RunLinearSieve(int n) {
  n = max(n, 1);
  least.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
      least[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > least[i] || i * x > n) {
        break;
      }
      least[i * x] = x;
    }
  }
  precalculated = n;
}

void RunSieve(int n) {
  RunLinearSieve(n);
}

template <typename T>
vector<pair<T, int>> Factorize(T x) {
  vector<pair<T, int>> ret;
  for (T i : primes) {
    T t = x / i;
    if (i > t) {
      break;
    }
    if (x == t * i) {
      int cnt = 0;
      while (x % i == 0) {
        x /= i;
        cnt++;
      }
      ret.emplace_back(i, cnt);
    }
  }
  if (x > 1) {
    ret.emplace_back(x, 1);
  }
  return ret;
}

}  // namespace factorizer

vector<int> GetFirsts(const vector<pair<int, int>>& a) {
  vector<int> b;
  for (auto& p : a) {
    b.push_back(p.first);
  }
  return b;
}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const int N = 100010;
const int MX = 555;

int delta[N][2];
int nxt[N][23];
int dist[MX * MX];
int pr[MX * MX];
vector<int> here[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> aa(n);
  for (int i = 0; i < n; i++) {
    cin >> aa[i].first;
    aa[i].second = i;
  }
  shuffle(aa.begin(), aa.end(), rng);
  vector<int> a(n);
  vector<int> real_id(n);
  for (int i = 0; i < n; i++) {
    a[i] = aa[i].first;
    real_id[i] = aa[i].second;
  }
  factorizer::RunSieve(40000);
  for (int start = 1; start < n; start++) {
    vector<vector<int>> f = {GetFirsts(factorizer::Factorize(a[0])), GetFirsts(factorizer::Factorize(a[start]))};
    vector<int> sz = {(int) f[0].size(), (int) f[1].size()};
    for (int i = start + 1; i < n; i++) {
      for (int r = 0; r < 2; r++) {
        delta[i][r] = 0;
        for (int j = 0; j < sz[r]; j++) {
          if (a[i] % f[r][j] == 0) {
            delta[i][r] |= (1 << j);
          }
        }
      }
    }
    for (int j = 0; j < sz[0] + sz[1]; j++) {
      nxt[n][j] = n;
    }
    for (int i = n - 1; i >= start + 1; i--) {
      for (int j = 0; j < sz[0]; j++) {
        if ((delta[i][0] & (1 << j)) == 0) {
          nxt[i][j] = i;
        } else {
          nxt[i][j] = nxt[i + 1][j];
        }
      }
      for (int j = 0; j < sz[1]; j++) {
        if ((delta[i][1] & (1 << j)) == 0) {
          nxt[i][sz[0] + j] = i;
        } else {
          nxt[i][sz[0] + j] = nxt[i + 1][sz[0] + j];
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      here[i].clear();
    }
    for (int t = 0; t < (1 << (sz[0] + sz[1])); t++) {
      dist[t] = n + 1;
    }
    int init = (1 << (sz[0] + sz[1])) - 1;
    dist[init] = start + 1;
    here[start + 1].push_back(init);
    for (int at = start + 1; at < n; at++) {
      for (int t : here[at]) {
        if (dist[t] != at) {
          continue;
        }
        for (int bit = 0; bit < sz[0]; bit++) {
          if ((t & (1 << bit)) == 0) {
            continue;
          }
          int to = nxt[at][bit];
          if (to == n) {
            continue;
          }
          int nt = t & (delta[to][0] | (((1 << (sz[0] + sz[1])) - 1) ^ ((1 << sz[0]) - 1)));
          if (to + 1 < dist[nt]) {
            dist[nt] = to + 1;
            pr[nt] = t;
            here[to + 1].push_back(nt);
          }
        }
        for (int bit = sz[0]; bit < sz[0] + sz[1]; bit++) {
          if ((t & (1 << bit)) == 0) {
            continue;
          }
          int to = nxt[at][bit];
          if (to == n) {
            continue;
          }
          int nt = t & ((delta[to][1] << sz[0]) | ((1 << sz[0]) - 1));
          if (to + 1 < dist[nt]) {
            dist[nt] = to + 1;
            pr[nt] = ~t;
            here[to + 1].push_back(nt);
          }
        }
      }
    }
    if (dist[0] <= n) {
      cout << "YES" << '\n';
      vector<int> res(n);
      for (int i = 0; i < start; i++) {
        res[real_id[i]] = 1;
      }
      res[real_id[start]] = 2;
      int t = 0;
      while (t != init) {
        int id = real_id[dist[t] - 1];
        if (pr[t] >= 0) {
          res[id] = 1;
          t = pr[t];
        } else {
          res[id] = 2;
          t = ~pr[t];
        }
      }
      for (int i = 0; i < n; i++) {
        if (res[i] == 0) {
          res[i] = rng() % 2 + 1;
        }
      }
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << res[i];
      }
      cout << '\n';
      return 0;
    }
    if (__gcd(a[0], a[start]) == a[0]) {
      break;
    }
    a[0] = __gcd(a[0], a[start]);
  }
  cout << "NO" << '\n';
  return 0;
}