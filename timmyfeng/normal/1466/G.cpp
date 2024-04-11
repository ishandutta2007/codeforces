#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

  int val = 0;

  mint() {}

  mint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  mint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  mint operator+=(mint oth) {
    val += oth.val;
    val -= (val >= M) ? M : 0;
    return *this;
  }

  mint operator-=(mint oth) {
    val -= oth.val;
    val += (val < 0) ? M : 0;
    return *this;
  }

  mint operator*=(mint oth) {
    val = 1LL * val * oth.val % M;
    return *this;
  }

  void operator++() {
    ++val;
    if (val == M) {
      val = 0;
    }
  }

  void operator--() {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }

  mint operator-() {
    mint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return mint(a) += b;
  }

  friend mint operator-(mint a, mint b) {
    return mint(a) -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.val == b.val;
  }

  friend bool operator!=(mint a, mint b) {
    return a.val != b.val;
  }

  friend ostream& operator<<(ostream &out, mint a) {
    out << a.val;
    return out;
  }

  friend mint pow(mint b, long long e = M - 2) {
    mint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

};

template <class T>
struct fenwick {

  vector<T> tree;
  int n;

  fenwick(int n) : n(n) {
    tree.resize(n + 1);
  }

  void update(int a, T val) {
    for ( ; a <= n; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a > 0; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  T query(int a, int b) {
    return query(b) - query(a - 1);
  }

  int lower_bound(T k) {
    int res = 0;
    T cur = 0;
    for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
      if (res + (1 << i) <= n && cur + tree[res + (1 << i)] < k) {
        res += 1 << i;
        cur += tree[res];
      }
    }
    return res + 1;
  }

};

const int K = 1000000 + 1;

mt19937 rng((unsigned long long) new char);
mint base = uniform_int_distribution<int>(137, M - 1)(rng);
mint pow_base[3 * K];
mint inv_base[3 * K];

void init_hash() {
  mint inv = pow(base);
  pow_base[0] = 1;
  inv_base[0] = 1;
  for (int j = 1; j < 3 * K; ++j) {
    pow_base[j] = pow_base[j - 1] * base;
    inv_base[j] = inv_base[j - 1] * inv;
  }
}

struct poly_hash {

  vector<mint> prefix;

  poly_hash() {}

  poly_hash(const string& s) {
    int n = s.size();
    prefix.resize(n + 1);
    for (int j = 0; j < n; ++j) {
      prefix[j + 1] = prefix[j] + s[j] * pow_base[j];
    }
  }

  mint query(int a, int b) {
    return (prefix[b] - prefix[a - 1]) * inv_base[a - 1];
  }

};

const int N = 100000;
const int A = 26;

int in[K], out[K], to[K][A], link[K], timer, m = 1;
vector<int> adj[K];

void dfs(int u) {
  in[u] = ++timer;
  for (auto c : adj[u]) {
    dfs(c);
  }
  out[u] = timer;
}

int song[N], indices[N], tail[N];
mint freq[A], ans[N];
string name[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init_hash();

  int n, q;
  string s, t;
  cin >> n >> q >> s >> t;

  for (int i = 0; i < q; ++i) {
    cin >> song[i] >> name[i];
    for (auto c : name[i]) {
      if (to[tail[i]][c - 'a'] == 0) {
        to[tail[i]][c - 'a'] = m++;
      }
      tail[i] = to[tail[i]][c - 'a'];
    }
  }

  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u != link[u]) {
      adj[link[u]].push_back(u);
    }
    for (int i = 0; i < A; ++i) {
      if (to[u][i] == 0) {
        to[u][i] = to[link[u]][i];
      } else {
        link[to[u][i]] = (u == 0) ? 0 : to[link[u]][i];
        que.push(to[u][i]);
      }
    }
  }

  dfs(0);

  fenwick<mint> fenw(m);

  iota(indices, indices + q, 0);
  sort(indices, indices + q, [&](int a, int b) {
    return song[a] < song[b];
  });

  int u = 0, j = 0;
  poly_hash hash_s;
  mint coeff = 1;

  for (int i = 0; i <= n; ++i) {
    if (i == 0) {
      for (auto c : s) {
        u = to[u][c - 'a'];
        fenw.update(in[u], 1);
      }
    } else {
      if ((int) s.size() <= K) {
        u = to[u][t[i - 1] - 'a'];
        fenw.update(in[u], 1);
        for (auto c : s) {
          u = to[u][c - 'a'];
          fenw.update(in[u], 1);
        }
        s += t[i - 1] + s;

        if ((int) s.size() > K) {
          hash_s = poly_hash(s);
        }
      } else {
        coeff *= 2;
        for (int j = 0; j < A; ++j) {
          freq[j] = 2 * freq[j] + (t[i - 1] - 'a' == j);
        }
      }
    }

    for ( ; j < q && song[indices[j]] == i; ++j) {
      int k = indices[j];
      ans[k] = fenw.query(in[tail[k]], out[tail[k]]) * coeff;
      if ((int) s.size() > K) {
        poly_hash hash_k(name[k]);
        for (int l = 0; l < (int) name[k].size(); ++l) {
          if (l > 0 &&
              hash_s.query(s.size() - l + 1, s.size()) != hash_k.query(1, l)) {
            continue;
          }
          if (l < (int) name[k].size() - 1 &&
              hash_s.query(1, name[k].size() - l - 1) != hash_k.query(l + 2, name[k].size())) {
            continue;
          }
          ans[k] += freq[name[k][l] - 'a'];
        }
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}