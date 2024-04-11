#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
std::size_t n;
int t, cnt[26];
char s[100001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    std::memset(cnt, 0, sizeof(cnt));
    std::scanf("%s", s);
    n = std::strlen(s);
    for (std::size_t i = 0; i < n; i++) cnt[s[i] - 'a']++;
    if (std::count_if(cnt, cnt + 26, [](const int &x) { return x > 0; }) == 1) {
      std::printf("%s\n", s);
      continue;
    }
    bool f = false;
    for (int i = 0; i < 26; i++)
      if (cnt[i] == 1) {
        std::printf("%c", 'a' + i);
        cnt[i] = 0;
        for (int j = 0; j < 26; j++)
          for (int k = 0; k < cnt[j]; k++) std::printf("%c", 'a' + j);
        std::printf("\n");
        f = true;
        break;
      }
    if (f) continue;
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < 26; i++)
      if (cnt[i]) v.emplace_back(i, cnt[i]);
    int tot = 0;
    for (std::size_t i = 1; i < v.size(); i++) tot += v[i].second;
    if (v[0].second <= tot + 2) {
      std::printf("%c%c", v[0].first + 'a', v[0].first + 'a');
      v[0].second -= 2;
      for (std::size_t i = 1; i < v.size() && v[0].second; i++)
        while (v[i].second && v[0].second) {
          std::printf("%c%c", v[i].first + 'a', v[0].first + 'a');
          v[i].second--, v[0].second--;
        }
      for (std::size_t i = 1; i < v.size(); i++)
        for (int j = 0; j < v[i].second; j++)
          std::printf("%c", v[i].first + 'a');
    } else if (v.size() == 2) {
      std::printf("%c", v[0].first + 'a');
      for (int i = 0; i < v[1].second; i++) std::printf("%c", v[1].first + 'a');
      for (int i = 1; i < v[0].second; i++) std::printf("%c", v[0].first + 'a');
    } else {
      std::printf("%c", v[0].first + 'a');
      std::printf("%c", v[1].first + 'a'), v[1].second--;
      for (int i = 1; i < v[0].second; i++) std::printf("%c", v[0].first + 'a');
      std::printf("%c", v[2].first + 'a'), v[2].second--;
      for (std::size_t i = 1; i < v.size(); i++)
        for (int j = 0; j < v[i].second; j++)
          std::printf("%c", v[i].first + 'a');
    }
    std::printf("\n");
  }
  return 0;
}