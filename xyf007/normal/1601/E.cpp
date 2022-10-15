#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  for (auto &&x : v) out << x << ' ';
  return out;
}
int n, q, k, m[300001], lg[300001], id[300001], stk[300001], top;
long long a[300001], b[300001];
std::vector<long long> s[300001], c[300001];
class SparseTable {
 public:
  int n_;
  std::vector<int> p_[20];
  std::vector<long long> a_;
  void Init(const std::vector<long long> &a) {
    a_ = a, n_ = a.size() - 1;
    for (int i = 0; i <= lg[n_]; i++) p_[i].resize(a.size());
  }
  void Generate() {
    for (int j = 1; j <= lg[n_]; j++)
      for (int i = 1; i + (1 << j) - 1 <= n_; i++)
        p_[j][i] = a_[p_[j - 1][i]] < a_[p_[j - 1][i + (1 << (j - 1))]]
                       ? p_[j - 1][i]
                       : p_[j - 1][i + (1 << (j - 1))];
  }
  int Query(int l, int r) {
    int len = lg[r - l + 1];
    return a_[p_[len][l]] < a_[p_[len][r - (1 << len) + 1]]
               ? p_[len][l]
               : p_[len][r - (1 << len) + 1];
  }
} st[300001];
void Init() {
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  std::deque<long long> q;
  for (int i = 1; i <= k; i++) {
    while (!q.empty() && a[i] < a[q.back()]) q.pop_back();
    q.push_back(i);
  }
  for (int i = k + 1; i <= n; i++) {
    while (!q.empty() && a[i] < a[q.back()]) q.pop_back();
    q.push_back(i);
    if (q.front() < i - k) q.pop_front();
    b[i] = a[q.front()];
  }
  for (int i = k + 1; i <= k + k && i <= n; i++) id[i] = 1;
  for (int i = 2 * k + 1; i <= n; i++) id[i] = id[i - k] + 1;
  for (int d = 0; d < k; d++) {
    c[d].reserve(n / k + 1);
    c[d].emplace_back(0);
    for (int i = k + (d == 0 ? k : d); i <= n; i += k) c[d].emplace_back(b[i]);
    m[d] = c[d].size() - 1;
    st[d].Init(c[d]);
    std::vector<int> nxt(c[d].size());
    c[d].emplace_back(-1);
    s[d].resize(m[d] + 2);
    stk[top = 1] = m[d] + 1;
    for (int i = m[d]; i >= 1; i--) {
      while (c[d][i] <= c[d][stk[top]]) top--;
      nxt[i] = stk[top];
      stk[++top] = i;
    }
    for (int i = m[d]; i >= 1; i--)
      s[d][i] = s[d][nxt[i]] + (nxt[i] - i) * c[d][i];
    for (int i = 1; i <= m[d]; i++) st[d].p_[0][i] = i;
    st[d].Generate();
  }
}
long long Query(int l, int r) {
  long long ans = a[l];
  if (r <= l + k - 1) return ans;
  int I = l % k, t = (r - l) / k, pl = id[l + k], pr = id[l + t * k],
      p = st[I].Query(pl, pr);
  return ans + s[I][pl] - s[I][p] + (pr - p + 1) * c[I][p];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  Init();
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << Query(l, r) << '\n';
  }
  return 0;
}