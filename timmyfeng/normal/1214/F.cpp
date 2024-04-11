#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

pair<int, int> a[N];
pair<int, int> b[N];
int n, m;

long long pre_sum[N];
int ans[N];
int ptr[4];

void init(pair<int, int>* c) {
  for (int i = 0; i < n; ++i) {
    cin >> c[i].first;
    c[i].second = i;
  }
  sort(c, c + n);
}

void move_a(int i, int x) {
  while (ptr[i] >= 0 && b[ptr[i]].first >= x) {
    --ptr[i];
  }
}

void move_b(int i, int x) {
  while (ptr[i] < n && a[ptr[i]].first < x) {
    ++ptr[i];
  }
}

void update(int i, int j, int x) {
  pre_sum[(i - j + n) % n] += x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m >> n;

  init(a);
  init(b);

  fill(ptr, ptr + 4, n - 1);
  for (int i = n - 1; i >= 0; --i) {
    move_a(0, a[i].first + m / 2 + 1);
    move_a(1, a[i].first);
    move_a(2, a[i].first - m / 2);
    move_a(3, 0);

    update(i, ptr[0], -2 * a[i].first);
    update(i, ptr[1], 2 * a[i].first);
    update(i, ptr[2], -2 * a[i].first);
    update(i, ptr[3], 2 * a[i].first);

    update(i, ptr[0], -m);
    update(i, ptr[2], m);
  }

  fill(ptr, ptr + 4, 0);
  for (int i = 0; i < n; ++i) {
    move_b(0, 0);
    move_b(1, b[i].first - m / 2);
    move_b(2, b[i].first + 1);
    move_b(3, b[i].first + m / 2 + 1);

    update(ptr[0], i, -2 * b[i].first);
    update(ptr[1], i, 2 * b[i].first);
    update(ptr[2], i, -2 * b[i].first);
    update(ptr[3], i, 2 * b[i].first);
  }

  pre_sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    pre_sum[0] += min(abs(a[i].first - b[i].first), m - abs(a[i].first - b[i].first));
  }

  int best = 0;
  for (int i = 1; i < n; ++i) {
    pre_sum[i] += pre_sum[i - 1];
    if (pre_sum[i] < pre_sum[best]) {
      best = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    ans[a[i].second] = b[(i - best + n) % n].second;
  }

  cout << pre_sum[best] << "\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
}