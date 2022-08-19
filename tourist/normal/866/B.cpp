/**
 *    author:  tourist
 *    created: 30.09.2017 20:08:25       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int eat[N], a[N], b[N];

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", eat + i, a + i, b + i);
    total += eat[i];
  }
  long long pizzas = (total + s - 1) / s;
  eat[n] = s * pizzas - total;
  a[n] = 0;
  b[n] = 0;
  n++;
  vector< pair<long long, long long> > a_to_b, b_to_a;
  long long ans = 0;
  long long cnt_a = 0, cnt_b = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      ans += eat[i] * 1LL * a[i];
      a_to_b.emplace_back(a[i] - b[i], eat[i]);
      cnt_a += eat[i];
    } else {
      ans += eat[i] * 1LL * b[i];
      b_to_a.emplace_back(b[i] - a[i], eat[i]);
      cnt_b += eat[i];
    }
  }
  long long best = (long long) 1e18;
  {
    long long extra = cnt_a % s;
    sort(a_to_b.begin(), a_to_b.end());
    long long cur = 0;
    for (int i = 0; i < (int) a_to_b.size(); i++) {
      auto &p = a_to_b[i];
      long long take = min(p.second, extra);
      cur += take * p.first;
      extra -= take;
    }
    best = min(best, cur);
  }
  {
    long long extra = cnt_b % s;
    sort(b_to_a.begin(), b_to_a.end());
    long long cur = 0;
    for (int i = 0; i < (int) b_to_a.size(); i++) {
      auto &p = b_to_a[i];
      long long take = min(p.second, extra);
      cur += take * p.first;
      extra -= take;
    }
    best = min(best, cur);
  }
  cout << (ans - best) << endl;
  return 0;
}