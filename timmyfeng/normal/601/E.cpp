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

const mint P = 10000019;
const int N = 35000 + 1;

vector<vector<long long>> maxi;
int when[N], v[N], w[N], k;
bool question[N];

void solve(vector<array<int, 3>> &schedules, int l, int r) {
  int prv = maxi.size();
  for (auto [a, b, c] : schedules) {
    if (a <= l && r <= b) {
      vector<long long> new_maxi(k + 1);
      for (int i = 0; i <= k; ++i) {
        new_maxi[i] = maxi.back()[i];
        if (i >= w[c]) {
          new_maxi[i] = max(new_maxi[i], maxi.back()[i - w[c]] + v[c]);
        }
      }
      maxi.push_back(new_maxi);
    }
  }

  if (l == r) {
    if (question[l]) {
      mint p = 1, ans = 0;
      for (int i = 1; i <= k; ++i) {
        ans += maxi.back()[i] * p;
        p *= P;
      }
      cout << ans << "\n";
    }
  } else {
    int m = (l + r) / 2;
    vector<array<int, 3>> left, right;
    for (auto [a, b, c] : schedules) {
      if (a > l || r > b) {
        if (a <= m) {
          left.push_back({a, b, c});
        }
        if (b > m) {
          right.push_back({a, b, c});
        }
      }
    }
    solve(left, l, m);
    solve(right, m + 1, r);
  }

  while ((int) maxi.size() > prv) {
    maxi.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i];
  }

  int q;
  cin >> q;

  vector<array<int, 3>> schedules;
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;

    if (t == 1) {
      when[++n] = i;
      cin >> v[n] >> w[n];
    } else if (t == 2) {
      int x;
      cin >> x;
      schedules.push_back({when[x], i, x});
      when[x] = -1;
    } else {
      question[i] = true;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (when[i] != -1) {
      schedules.push_back({when[i], q, i});
    }
  }

  maxi.emplace_back(k + 1);
  solve(schedules, 0, q);
}