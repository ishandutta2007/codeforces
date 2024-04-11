#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

  int value;

  mint() : value(0) {}

  template <class T>
  mint(T x) {
    value = x % M;
    if (value < 0) {
      value += M;
    }
  }

  mint & operator++() {
    if (++value == M) {
      value = 0;
    }
    return *this;
  }

  mint & operator--() {
    if (--value == -1) {
      value = M - 1;
    }
    return *this;
  }

  mint operator++(int) {
    mint res = *this;
    ++*this;
    return res;
  }

  mint operator--(int) {
    mint res = *this;
    --*this;
    return res;
  }

  mint & operator+=(mint oth) {
    value += oth.value;
    if (value >= M) {
      value -= M;
    }
    return *this;
  }

  mint & operator-=(mint oth) {
    value -= oth.value;
    if (value < 0) {
      value += M;
    }
    return *this;
  }

  mint & operator*=(mint oth) {
    value = (long long) value * oth.value % M;
    return *this;
  }

  mint operator+() const {
    return *this;
  }

  mint operator-() const {
    return mint() - *this;
  }

  mint pow(long long e = M - 2) const {
    mint res = 1, b = *this;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return a += b;
  }

  friend mint operator-(mint a, mint b) {
    return a -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.value == b.value;
  }

  friend bool operator!=(mint a, mint b) {
    return a.value != b.value;
  }

  friend ostream & operator<<(ostream &out, mint a) {
    out << a.value;
    return out;
  }

};

const int N = 1000 + 1;
const int K = 50 + 1;
const int A = 10;

mint ans, coeff[K][N * K], value[K][N * K];
int to[N * K][A], link[N * K];
bool gold[N * K];

void push(int u, string l, string r) {
  if (gold[u]) {
    mint x = 0, y = 0;
    for (auto i : l) {
      x = 10 * x + i - '0';
    }
    for (auto i : r) {
      y = 10 * y + i - '0';
    }
    ans += y - x + 1;
    return;
  }

  if (count(l.begin(), l.end(), '0') == (int) l.size()) {
    if (count(r.begin(), r.end(), '9') == (int) r.size()) {
      ++coeff[l.size()][u];
      return;
    }
  }

  for (char c = l[0]; c <= r[0]; ++c) {
    push(to[u][c - '0'],
      (c > l[0]) ? string(l.size() - 1, '0') : l.substr(1),
      (c < r[0]) ? string(r.size() - 1, '9') : r.substr(1)
    );
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, x, y;
  cin >> s >> x >> y;
  int d = x.size();

  int m = 1;
  for (int i = 0; i + d / 2 <= (int) s.size(); ++i) {
    int u = 0;
    for (int j = 0; j < d / 2; ++j) {
      int c = s[i + j] - '0';
      if (to[u][c] == 0) {
        to[u][c] = m++;
      }
      u = to[u][c];
    }
    gold[u] = true;
  }

  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    int p = link[u];
    for (int i = 0; i < A; ++i) {
      if (to[u][i] == 0) {
        to[u][i] = to[p][i];
      } else {
        link[to[u][i]] = (u == 0) ? 0 : to[p][i];
        que.push(to[u][i]);
      }
    }
  }

  push(0, x, y);

  for (int i = 0; i <= d; ++i) {
    for (int j = 0; j < m; ++j) {
      if (gold[j]) {
        value[i][j] = mint(10).pow(i);
      } else if (i > 0) {
        for (int k = 0; k < A; ++k) {
          value[i][j] += value[i - 1][to[j][k]];
        }
      }
      ans += coeff[i][j] * value[i][j];
    }
  }

  cout << ans << "\n";
}