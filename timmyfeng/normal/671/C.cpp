#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  int maxi = 0, mini = 0, lazy = 0;
  long long sum = 0;

  void apply(int value, int l, int r) {
    sum = (long long) (r - l + 1) * value;
    lazy = maxi = mini = value;
  }

  void pull() {
    sum = right->sum + left->sum;
    maxi = max(right->maxi, left->maxi);
    mini = min(right->mini, left->mini);
  }

  void push(int l, int r) {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }

    if (lazy > 0) {
      int m = (l + r) / 2;
      left->apply(lazy, l, m);
      right->apply(lazy, m + 1, r);
      lazy = 0;
    }
  }

  void update(int a, int value, int l, int r) {
    if (l > a || mini >= value) {
      return;
    } else if (r <= a && maxi <= value) {
      apply(value, l, r);
    } else if (l < r) {
      push(l, r);
      int m = (l + r) / 2;
      left->update(a, value, l, m);
      right->update(a, value, m + 1, r);
      pull();
    }
  }

};

const int N = 200000 + 1;

vector<int> divisors[N], where[N];
int a[N], freq[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      divisors[j].push_back(i);
    }
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i < N; ++i) {
    where[i].push_back(n);
  }

  for (int i = n - 1; i >= 0; --i) {
    for (auto d : divisors[a[i]]) {
      where[d].push_back(i);
    }
  }

  segtree *weird = new segtree();
  for (int i = 1; i < N; ++i) {
    if (2 < where[i].size()) {
      weird->update(where[i][2], i, 1, n);
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    weird->update(i, N, 1, n);
    ans += weird->sum - (long long) N * i;
    for (auto d : divisors[a[i]]) {
      if (++freq[d] <= 2 && 2 - freq[d] < (int) where[d].size()) {
        weird->update(where[d][2 - freq[d]], d, 1, n);
      }
    }
  }

  cout << ans << "\n";
}