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
int n;
std::string s[101], t[201];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> s[i];
  for (int i = 0; i < n; i++) {
    if (s[i].find("theseus") != std::string::npos) {
      std::cout << "YES";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) t[i].resize(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) t[i][j] = s[j][i];
  for (int i = 0; i < n; i++) {
    if (t[i].find("theseus") != std::string::npos) {
      std::cout << "YES";
      return 0;
    }
  }
  for (int x = 1 - n; x <= n - 1; x++) {
    std::string tmp;
    for (int i = 0, j = i - x; i < n; i++, j++)
      if (j >= 0 && j < n) tmp += s[i][j];
    if (tmp.find("theseus") != std::string::npos) {
      std::cout << "YES";
      return 0;
    }
  }
  std::cout << "NO";
  return 0;
}