#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int t, n, k, cnt[26];
char s[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k >> (s + 1);
    if (n % k) {
      std::cout << "-1\n";
      continue;
    }
    std::memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      cnt[s[i] - 'a']++;
    }
    if (std::all_of(cnt, cnt + 26,
                    [](const int &x) -> bool { return !(x % k); })) {
      for (int i = 1; i <= n; i++) {
        std::cout << s[i];
      }
      std::cout << '\n';
      continue;
    }
    int tmp = 0;
    for (int i = 0; i < 26; i++) {
      if (!(cnt[i] % k)) {
        continue;
      }
      tmp += k - cnt[i] % k;
    }
    bool f = false;
    for (int i = n; i >= 1 && !f; i--) {
      if (!(--cnt[s[i] - 'a'] % k)) {
        tmp -= k - 1;
      } else {
        tmp++;
      }
      for (int j = s[i] - 'a' + 1; j < 26 && !f; j++) {
        if (!(cnt[j]++ % k)) {
          tmp += k - 1;
        } else {
          tmp--;
        }
        if (n - i >= tmp) {
          f = true;
          for (int l = 1; l < i; l++) {
            std::cout << s[l];
          }
          std::cout << static_cast<char>(j + 'a');
          std::string ans;
          for (int l = 1; l < 26; l++) {
            if (!(cnt[l] % k)) {
              continue;
            }
            for (int u = 0; u < k - cnt[l] % k; u++) {
              ans.push_back(static_cast<char>(l + 'a'));
            }
          }
          for (size_t u = 0; u < n - i - ans.size(); u++) {
            std::cout << 'a';
          }
          std::cout << ans << '\n';
          break;
        }
        if (!(--cnt[j] % k)) {
          tmp -= k - 1;
        } else {
          tmp++;
        }
      }
    }
  }
  return 0;
}