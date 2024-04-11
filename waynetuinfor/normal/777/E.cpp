#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n;
long long dp[maxn];
vector<int> v;

struct Ring { int i, o, h; } r[maxn];
vector<Ring> osas;

struct BIT {
  int _n;
  long long bit[maxn << 1];
  void init(int hao) {
    memset(bit, 0, sizeof(bit));
    _n = hao;
  }
  #define lowbit(x) (x & -x)
  void add(int x, long long v) {
    for (int i = x; i <= _n; i += lowbit(i)) bit[i] = max(bit[i], v);
  }
  long long sum(int x) {
    long long ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret = max(ret, bit[i]);
    return ret;
  }
  #undef lowbit
} bit;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> r[i].i >> r[i].o >> r[i].h;
  sort(r, r + n, [](const Ring& a, const Ring& b) {
    return a.o < b.o;
  });
  for (int i = 0; i < n; ) {
    Ring tmp = r[i];
    int j = i + 1;
    while (r[j].o == r[i].o) tmp.i = min(tmp.i, r[j].i), tmp.h += r[j].h, ++j;
    i = j;
    osas.push_back(tmp);
  }
  for (Ring r : osas) v.push_back(r.i), v.push_back(r.o);
  sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
  bit.init((int)v.size());
  sort(osas.begin(), osas.end(), [](const Ring& a, const Ring& b) {
    return a.o > b.o;
  });
  long long Max = 0ll;
  for (int i = 0; i < osas.size(); ++i) {
    int ind = lower_bound(v.begin(), v.end(), osas[i].o) - v.begin() + 1;
    dp[i] = bit.sum(ind - 1) + osas[i].h;
    ind = lower_bound(v.begin(), v.end(), osas[i].i) - v.begin() + 1;
    bit.add(ind, dp[i]);
    Max = max(Max, dp[i]);
    // cout << "dp[" << i << "] = " << dp[i] << '\n';
  }
  cout << Max << '\n';
  return 0;
}