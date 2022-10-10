#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 1e6 + 5;

vector<bool> is_prime(N, true);

void build() {
  for (int i = 2; i < N; ++i) {
    if (!is_prime[i]) continue;
    for (int j = 2 * i; j < N; j += i) {
      is_prime[j] = false;
    }
  }
}
int res[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif
  build();
  int t;
  cin >> t;
  vector<pair<int, int>> queries(t);
  for (int i = 0; i < t; ++i) {
    auto& q = queries[i];
    cin >> q.first;
    q.second = i;
  }
  sort(all(queries));
  int last_t = 1;
  queue<int> lonely;
  for (auto& q : queries) {
    while (last_t < q.first) {
      ++last_t;
      if (is_prime[last_t]) {
        lonely.emplace(last_t);
      }
    }
    while (!lonely.empty() && 1LL * lonely.front() * lonely.front() <= last_t) {
      lonely.pop();
    }
    q.first = sz(lonely) + 1;
    swap(q.second, q.first);
  }
  sort(all(queries));
  for (auto& q : queries) {
    cout << q.second << endl;
  }

  return 0;
}