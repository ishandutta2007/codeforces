#include <algorithm>
#include <iostream>
#include <map>
constexpr int kMask = 1073741823;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int n, s[600001], nxt[600001], anc[600001], stk[600001], top;
long long a[600001], sum;
__int128_t ans;
std::map<long long, int> mp;
long long Query(int pos) {
  return a[*std::lower_bound(stk + 1, stk + top + 1, pos)];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  char ch;
  std::cin >> ch >> a[1];
  s[1] = ch - 'a';
  stk[++top] = 1;
  std::cout << (ans = a[1]) << '\n';
  for (int i = 2, j = 0; i <= n; i++) {
    char c[10];
    long long w;
    std::cin >> c >> w;
    s[i] = (c[0] - 'a' + ans) % 26, a[i] = w ^ (ans & kMask);
    while (j && s[j + 1] != s[i]) j = nxt[j];
    if (s[j + 1] == s[i]) j++;
    nxt[i] = j;
    anc[i - 1] = s[nxt[i - 1] + 1] == s[i] ? anc[nxt[i - 1]] : nxt[i - 1];
    for (int k = nxt[i - 1]; k;) {
      if (s[k + 1] == s[i]) {
        k = anc[k];
        continue;
      }
      long long v = Query(i - k);
      sum -= v;
      if (!--mp[v]) mp.erase(v);
      k = nxt[k];
    }
    if (s[i] == s[1]) mp[a[i]]++, sum += a[i];
    while (top && a[i] <= a[stk[top]]) top--;
    stk[++top] = i;
    int ct = 0;
    for (auto it = mp.upper_bound(a[i]); it != mp.end();) {
      sum -= it->second * (it->first - a[i]);
      ct += it->second;
      mp.erase(it++);
    }
    mp[a[i]] += ct;
    std::cout << (ans += a[stk[1]] + sum) << '\n';
  }
  return 0;
}