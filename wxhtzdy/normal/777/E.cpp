#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
struct node {
  long long a = 0; // don't forget to set default value
  inline void operator += (node &other) {
    a = max(a, other.a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), h(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> h[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (b[i] != b[j]) {
      return b[i] > b[j];
    } else {
      return a[i] > a[j];
    }
  });
  vector<int> cs;
  for (int i = 0; i < n; i++) {
    cs.push_back(a[i]);
    cs.push_back(b[i]);
  }
  sort(cs.begin(), cs.end());
  cs.erase(unique(cs.begin(), cs.end()), cs.end());
  int m = (int) cs.size();
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(cs.begin(), cs.end(), a[i]) - cs.begin();
    b[i] = lower_bound(cs.begin(), cs.end(), b[i]) - cs.begin();
  }
  vector<long long> dp(n);
  fenwick<node> fenw(m);
  for (int id = 0; id < n; id++) {
    int i = order[id];
    dp[i] = fenw.get(b[i] - 1).a + h[i];
    fenw.modify(a[i], {dp[i]});
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}