#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;
const int N = 3e5 + 1;
const int K = 41;

int pre_sum[K][N];
int a[K][2];
int rr[N];
int ll[N];

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int fact[N];
int inv_fact[N];

void init_fact() {
  inv_fact[1] = 1;
  for (int i = 2; i < N; ++i) {
    inv_fact[i] = M - mul(M / i, inv_fact[M % i]);
  }

  fact[0] = 1;
  inv_fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = mul(inv_fact[i - 1], inv_fact[i]);
  }
}

int choose(int n, int k) {
  if (k < 0 || k > n || n < 0) {
    return 0;
  }
  return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init_fact();

  int n, m;
  cin >> n >> m;

  vector<array<int, 2>> points;
  for (int i = 0; i < n; ++i) {
    cin >> ll[i] >> rr[i];
    points.push_back({ll[i], 1});
    points.push_back({rr[i] + 1, -1});
  }

  int ptr = 0;
  int cnt = 0;
  sort(points.begin(), points.end());
  for (int i = 1; i <= n; ++i) {
    while (ptr < 2 * n && points[ptr][0] == i) {
      cnt += points[ptr][1];
      ++ptr;
    }
    for (int j = 0; j < K; ++j) {
      pre_sum[j][i] = choose(cnt - j, i - j);
    }
  }

  for (int i = 0; i < K; ++i) {
    for (int j = 1; j <= n; ++j) {
      pre_sum[i][j] = add(pre_sum[i][j], pre_sum[i][j - 1]);
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
  }

  int ans = 0;
  for (int mask = 0; mask < (1 << m); ++mask) {
    set<int> must;
    for (int i = 0; i < m; ++i) {
      if ((mask & (1 << i)) > 0) {
        for (int j = 0; j < 2; ++j) {
          must.insert(a[i][j]);
        }
      }
    }

    int l = 1;
    int r = n;
    for (int i : must) {
      l = max(l, ll[i]);
      r = min(r, rr[i]);
    }

    if (l > r) {
      continue;
    }

    int val = sub(pre_sum[must.size()][r], pre_sum[must.size()][l - 1]);
    if (__builtin_popcount(mask) % 2 == 0) {
      ans = add(ans, val);
    } else {
      ans = sub(ans, val);
    }
  }
  cout << ans << "\n";
}