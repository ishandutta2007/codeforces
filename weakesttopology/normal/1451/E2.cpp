#include <bits/stdc++.h>
int query(std::string_view s, int i, int j) {
  std::cout << s << ' ' << i + 1 << ' ' << j + 1 << std::endl;
  int x;
  std::cin >> x;
  if (x == -1) exit(0);
  return x;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 1; i < N; ++i) {
    a[i] = query("XOR", 0, i);
  }
  std::vector<int> I(N - 1);
  std::iota(I.begin(), I.end(), 1);
  auto f = [&](int i) {
    return std::pair(std::popcount((unsigned)a[i]), a[i]);
  };
  std::sort(I.begin(), I.end(), [&](int i, int j) { return f(i) > f(j); });
  int x = I[0], y = I[1];
  bool uniq = true;
  for (int j = 0; j < N - 1; ++j) {
    if (j + 1 < N - 1 && a[I[j]] == a[I[j + 1]]) {
      uniq = false;
      x = I[j];
      y = I[j + 1];
      break;
    } else if (a[I[j]] == 0) {
      uniq = false;
      x = 0;
      y = I[j];
      break;
    }
  }
  if (uniq) {
    assert(f(x).first == f(y).first + 1);
    a[0] = N - 1;
    a[0] &= ~query("AND", x, y);
    a[0] &= ~(a[x] ^ a[y]);
    a[0] |= query("AND", 0, y);
  } else {
    a[0] = a[y] ^ query("AND", x, y);
  }
  for (int i = 1; i < N; ++i) {
    a[i] ^= a[0];
  }
  std::cout << '!';
  for (int i = 0; i < N; ++i) {
    std::cout << ' ' << a[i];
  }
  std::cout << '\n';
  exit(0);
}