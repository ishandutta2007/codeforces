#include <iostream>
#include <string>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::string s;
  std::cin >> s;
  for (auto &&ch : s) ch -= 'a';
  if (s.size() == 3) {
    s[0] += 't' - 'a';
    s[1] += 'h' - 'a';
    s[2] += 'e' - 'a';
  } else if (s.size() == 4) {
    std::cout << "none";
    return 0;
  } else if (s.size() == 5) {
    s[0] += 'b' - 'a';
    s[1] += 'u' - 'a';
    s[2] += 'f' - 'a';
    s[3] += 'f' - 'a';
    s[4] += 'y' - 'a';
  } else if (s.size() == 6) {
    s[0] += 's' - 'a';
    s[1] += 'l' - 'a';
    s[2] += 'a' - 'a';
    s[3] += 'y' - 'a';
    s[4] += 'e' - 'a';
    s[5] += 'r' - 'a';
  } else {
    s[0] += 'v' - 'a';
    s[1] += 'a' - 'a';
    s[2] += 'm' - 'a';
    s[3] += 'p' - 'a';
    s[4] += 'i' - 'a';
    s[5] += 'r' - 'a';
    s[6] += 'e' - 'a';
  }
  for (auto &&ch : s) (ch %= 26) += 'a';
  std::cout << s;
  return 0;
}