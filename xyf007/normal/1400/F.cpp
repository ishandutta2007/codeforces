#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std::literals::string_literals;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
char s[1005];
int n, x, ch[5001][9], tot, fail[5001], f[1001][5001];
bool ed[5001];
std::vector<std::string> il;
bool Check(const std::string &s) {
  for (std::size_t i = 0; i < s.size(); i++) {
    int sum = 0;
    for (std::size_t j = i; j < s.size(); j++)
      if (x % (sum += (s[j] - '0')) == 0 && sum != x) return false;
  }
  return true;
}
void Dfs(const std::string &s, int cur) {
  if (cur > x) return;
  if (cur == x) {
    if (Check(s)) il.push_back(s);
    return;
  }
  for (char i = '1'; i <= '9'; i++) Dfs(s + i, cur + i - '0');
}
void Insert(const std::string &s) {
  int now = 0;
  for (const auto &c : s) {
    if (!ch[now][c - '1']) ch[now][c - '1'] = ++tot;
    now = ch[now][c - '1'];
  }
  ed[now] = true;
}
void Build() {
  std::queue<int> q;
  for (int i = 0; i < 9; i++)
    if (ch[0][i]) q.emplace(ch[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 9; i++)
      if (ch[u][i]) {
        fail[ch[u][i]] = ch[fail[u]][i];
        ed[ch[u][i]] |= ed[fail[ch[u][i]]];
        q.emplace(ch[u][i]);
      } else {
        ch[u][i] = ch[fail[u]][i];
      }
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> (s + 1) >> x, n = std::strlen(s + 1);
  il.reserve(3000);
  Dfs(""s, 0);
  for (const auto &s : il) Insert(s);
  Build();
  std::memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= tot; j++)
      if (f[i][j] <= n) {
        checkmin(f[i + 1][j], f[i][j] + 1);
        if (!ed[ch[j][s[i + 1] - '1']])
          checkmin(f[i + 1][ch[j][s[i + 1] - '1']], f[i][j]);
      }
  std::cout << *std::min_element(f[n], f[n] + tot + 1);
  return 0;
}