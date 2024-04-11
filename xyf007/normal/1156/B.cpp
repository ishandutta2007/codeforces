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
constexpr char s0[] = "acegikmoqsuwybdfhjlnprtvxz",
               s1[] = "bdfhjlnprtvxzacegikmoqsuwy";
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, cnt[26];
std::string s;
bool Check(const std::string &t) {
  for (std::size_t i = 0; i + 1 < t.size(); i++)
    if (std::abs(t[i] - t[i + 1]) == 1) return false;
  return true;
}
void Solve() {
  std::cin >> s;
  std::memset(cnt, 0, sizeof(cnt));
  for (std::size_t i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
  std::string t;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < cnt[s0[i] - 'a']; j++) t += s0[i];
  if (Check(t)) {
    std::cout << t << '\n';
    return;
  }
  t.clear();
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < cnt[s1[i] - 'a']; j++) t += s1[i];
  if (Check(t)) {
    std::cout << t << '\n';
    return;
  }
  std::cout << "No answer\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}