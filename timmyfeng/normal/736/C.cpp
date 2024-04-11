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

const int N = 100;
const int K = 20 + 1;

mint black[N][K];
mint white[N][K];

mint new_black[K];
mint new_white[K];

vector<int> adj[N];
int k;

void dfs(int u, int p) {
  black[u][0] = 1;
  white[u][0] = 1;

  for (auto c : adj[u]) {
    if (c != p) {
      dfs(c, u);

      fill(new_black, new_black + k + 1, 0);
      fill(new_white, new_white + k + 1, 0);

      for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
          new_black[min(i, j + 1)] += black[u][i] * black[c][j];
          if (j + 1 <= k) {
            new_white[max(i, j + 1)] += white[u][i] * white[c][j];
          }

          if (i + j + 1 <= k) {
            new_black[i] += black[u][i] * white[c][j];
            new_black[j + 1] += white[u][i] * black[c][j];
          } else {
            new_white[i] += white[u][i] * black[c][j];
            if (j + 1 <= k) {
              new_white[j + 1] += black[u][i] * white[c][j];
            }
          }
        }
      }

      copy(new_black, new_black + k + 1, black[u]);
      copy(new_white, new_white + k + 1, white[u]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> k;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, -1);

  cout << accumulate(black[0], black[0] + k + 1, (mint) 0) << "\n";
}