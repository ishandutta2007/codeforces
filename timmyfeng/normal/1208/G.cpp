#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000 + 1;

struct state {
  int cost, x;
  bool operator<(state oth) const {
    return cost > oth.cost;
  }
};

int divisors[N];
int phi[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << 3 << "\n";
    exit(0);
  }

  iota(phi + 1, phi + N, 1);
  priority_queue<state> que;

  for (int i = 2; i <= n; ++i) {
    for (int j = 2 * i; j <= n; j += i) {
      ++divisors[j];
      if (phi[i] == i) {
        phi[j] /= i;
        phi[j] *= i - 1;
      }
    }

    if (phi[i] == i) {
      --phi[i];
      que.push({phi[i], i});
    }
  }

  long long ans = 1;
  for (int i = 0; i <= k; ++i) {
    state s = que.top();
    que.pop();

    ans += s.cost;
    for (int j = 2 * s.x; j <= n; j += s.x) {
      if (--divisors[j] == 0) {
        que.push({phi[j], j});
      }
    }
  }

  cout << ans << "\n";
}