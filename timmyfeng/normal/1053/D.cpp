#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int P = 2e6 + 1;
const int M = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int n;

struct segment_tree {

  struct node {
    vector<int> reqs;
    void apply(int l, int r, int a) {
      reqs.push_back(a);
    }
  } tree[N * 4];

  template <class... T>
  void update(int v, int l, int r, int a, int b, const T&... val) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      tree[v].apply(l, r, val...);
    } else {
      int m = (l + r) / 2;
      update(v * 2, l, m, a, b, val...);
      update(v * 2 + 1, m + 1, r, a, b, val...);
    }
  }

  template <class... T>
  void update(int a, int b, const T&... val) {
    update(1, 0, n - 1, a, b, val...);
  }

} qt;

int sieve[P];
int ans;

vector<tuple<int, int, int, bool>> stk;
bool flag[P];
int mx[P];

int cur = 1;
bool ok;

void push(int);

void update(int p, int a, bool f) {
  stk.emplace_back(p, mx[p], cur, flag[p]);
  if (f && mx[p] > 0) {
    push(p - 1);
  } else {
    if (flag[p]) {
      push(p - 1);
    }
    flag[p] |= (mx[p] == 0);
    while (mx[p] < a) {
      cur = mul(cur, p);
      ++mx[p];
    }
  }
  flag[p] &= f;
}

void push(int i) {
  while (i > 1) {
    int p = sieve[i];
    int a = 0;
    while (i % p == 0) {
      i /= p;
      ++a;
    }
    update(p, a, false);
  }
}

void solve(int v, int l, int r) {
  int pre = stk.size();
  for (int p : qt.tree[v].reqs) {
    update(p, 1, true);
  }

  if (l == r) {
    ok |= (cur == ans);
  } else {
    int m = (l + r) / 2;
    solve(v * 2, l, m);
    solve(v * 2 + 1, m + 1, r);
  }

  while (int(stk.size()) > pre) {
    auto [p, a, c, f] = stk.back();
    stk.pop_back();
    flag[p] = f;
    mx[p] = a;
    cur = c;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < P; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < P; j += i) {
        sieve[j] = i;
      }
    }
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    update(p, 1, true);
    if (i > 0) {
      qt.update(0, i - 1, p);
    }
    if (i + 1 < n) {
      qt.update(i + 1, n - 1, p);
    }
  }

  memset(flag, false, sizeof flag);
  memset(mx, 0, sizeof mx);
  ans = cur;
  cur = 1;

  solve(1, 0, n - 1);

  cout << add(ans, ok) << "\n";
}