#include <bits/stdc++.h>
using namespace std;

// atcoder library - math
long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

const int N = 200'000;

bool visited[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, a, b;
  cin >> m >> a >> b;
  int n = min(++m, a + b);

  priority_queue<int, vector<int>, greater<int>> que;
  visited[0] = true;
  que.push(0);

  long long ans = 0;
  int count = 0;

  for (int i = 0; i < n; ++i) {
    while (!que.empty() && que.top() <= i) {
      int u = que.top();
      que.pop();

      if (u - b >= 0 && !visited[u - b]) {
        visited[u - b] = true;
        que.push(u - b);
      }

      if (u + a < min(m, a + b) && !visited[u + a]) {
        visited[u + a] = true;
        que.push(u + a);
      }
      ++count;
    }
    ans += count;
  }

  ans += floor_sum(m, __gcd(a, b), 1, 0) + m;
  ans -= floor_sum(n, __gcd(a, b), 1, 0) + n;

  cout << ans << "\n";
}