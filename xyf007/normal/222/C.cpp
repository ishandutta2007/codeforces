#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, m, a[100001], b[100001], p[700001], tot, id[10000001], cnta[700001],
    cntb[700001];
bool not_prime[10000001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  not_prime[1] = true;
  for (int i = 2; i <= 10000000; i++) {
    if (!not_prime[i]) {
      p[id[i] = ++tot] = i;
    }
    for (int j = 1; j <= tot && i * p[j] <= 10000000; j++) {
      not_prime[i * p[j]] = true;
      if (!(i % p[j])) {
        break;
      }
    }
  }
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int tmp = a[i];
    for (int j = 1; j <= tot && p[j] * p[j] <= tmp; j++) {
      if (!(tmp % p[j])) {
        while (!(tmp % p[j])) {
          cnta[j]++;
          tmp /= p[j];
        }
      }
    }
    if (tmp > 1) {
      cnta[id[tmp]]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    int tmp = b[i];
    for (int j = 1; j <= tot && p[j] * p[j] <= tmp; j++) {
      if (!(tmp % p[j])) {
        while (!(tmp % p[j])) {
          cntb[j]++;
          tmp /= p[j];
        }
      }
    }
    if (tmp > 1) {
      cntb[id[tmp]]++;
    }
  }
  for (int i = 1; i <= tot; i++) {
    cnta[i] = cntb[i] = std::min(cnta[i], cntb[i]);
  }
  for (int i = 1; i <= n; i++) {
    int tmp = a[i];
    for (int j = 1; j <= tot && p[j] * p[j] <= tmp; j++) {
      if (!(tmp % p[j])) {
        while (!(tmp % p[j])) {
          if (cnta[j]) {
            a[i] /= p[j];
            cnta[j]--;
          }
          tmp /= p[j];
        }
      }
    }
    if (tmp > 1 && cnta[id[tmp]]) {
      a[i] /= tmp;
      cnta[id[tmp]]--;
    }
  }
  for (int i = 1; i <= m; i++) {
    int tmp = b[i];
    for (int j = 1; j <= tot && p[j] * p[j] <= tmp; j++) {
      if (!(tmp % p[j])) {
        while (!(tmp % p[j])) {
          if (cntb[j]) {
            b[i] /= p[j];
            cntb[j]--;
          }
          tmp /= p[j];
        }
      }
    }
    if (tmp > 1 && cntb[id[tmp]]) {
      b[i] /= tmp;
      cntb[id[tmp]]--;
    }
  }
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
  for (int i = 1; i <= m; i++) {
    std::cout << b[i] << ' ';
  }
  return 0;
}