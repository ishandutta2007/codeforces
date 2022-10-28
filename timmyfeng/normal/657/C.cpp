#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int member[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, b, c;
  cin >> n >> k >> b >> c;
  b = min(b, c * 5);

  for (int i = 0; i < n; ++i) {
    cin >> member[i];
  }
  sort(member, member + n);

  long long ans = LLONG_MAX;
  for (int i = 0; i < 5; ++i) {
    long long sum = 0;
    priority_queue<long long> que;
    for (int j = 0; j < n; ++j) {
      long long contribution = member[j] - i, cost = 0;
      while (contribution % 5 != 0) {
        ++contribution;
        cost += c;
      }
      cost -= contribution / 5 * b;

      sum += cost;
      que.push(cost);
      while ((int) que.size() > k) {
        sum -= que.top();
        que.pop();
      }

      if ((int) que.size() == k) {
        ans = min(ans, sum + contribution / 5 * b * k);
      }
    }
  }

  cout << ans << "\n";
}