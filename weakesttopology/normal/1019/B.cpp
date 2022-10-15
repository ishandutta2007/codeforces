#include <bits/stdc++.h>
int query(int i) {
  std::cout << "? " << i + 1 << std::endl;
  int res;
  std::cin >> res;
  return res;
}
void answer(int i) {
  std::cout << "! " << (i == -1 ? -1 : i + 1) << std::endl;
  exit(0);
}
int sgn(int x) {
  return x <= 0 ? x < 0 ? -1 : 0 : +1;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  auto C = [&](int i) {
    return (i + N / 2) % N;
  };
  int l = 0, r = C(l);
  int x = query(l), y = query(r);
  int s = sgn(y - x);
  while (l + 1 < r) {
    int m = (r + l) / 2;
    sgn(query(C(m)) - query(m)) == s ? l = m : r = m;
  }
  for (auto i : {l, r}) {
    if (query(i) == query(C(i))) {
      answer(i);
    }
  }
  answer(-1);
  exit(0);
}