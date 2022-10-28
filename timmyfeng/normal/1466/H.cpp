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

const int N = 40 + 1;

using state = tuple<int, int, int, int, map<int, int>>;

mint choose[N][N], fact[N];
bool visited[N];
int perm[N], n;

mint calc(int k) {
  return choose[n][k + 1] * fact[k] * fact[n - k - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < N; ++i) {
    choose[i][0] = choose[i][i] = 1;
    fact[i] = (i == 0) ? 1 : fact[i - 1] * i;
    for (int j = 1; j < i; ++j) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> perm[i];
    --perm[i];
  }

  map<int, int> cycles;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      int j = i, l = 0;
      while (!visited[j]) {
        visited[j] = true;
        j = perm[j];
        ++l;
      }
      ++cycles[l];
    }
  }

  mint ans = 0;
  cycles[n + 1] = 0;
  map<state, mint> ways;
  ways.insert({{0, cycles.begin()->first, 0, 0, cycles}, 1});

  while (!ways.empty()) {
    auto [s, x] = *ways.begin();
    auto [i, j, p, c, count] = s;
    ways.erase(ways.begin());

    if (j > n) {
      if (c > 0) {
        if (i + c == n) {
          ans += x;
        } else {
          state t = {i + c, count.begin()->first, c, 0, count};
          ways[t] += x;
        }
      }
    } else {
      mint y = pow(calc(n - i - 1), j);
      if (p > 0) {
        y -= pow(calc(n - i - 1 + p), j);
      }

      state t = {i, count.upper_bound(j)->first, p, c, count};
      for (int k = 0; k <= count[j]; ++k) {
        ways[t] += x * pow(y, k) * choose[count[j]][k];
        get<3>(t) += j;
        --get<4>(t)[j];
      }
    }
  }

  cout << ans << "\n";
}