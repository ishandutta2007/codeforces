#include <bits/stdc++.h>

template <typename T>
struct BIT {
  static int lsb(int b) {
    return b & -b;
  }
  int N, h;
  std::vector<T> ft;
  BIT(int N) : N(N), h(std::__lg(N)), ft(N + 1, T()) {}
  template <typename Iterator>
  BIT(Iterator first, Iterator last) : BIT(last - first) {
    for (int i = 1; i <= N; ++i) {
      ft[i] = first[i - 1] + ft[i - 1];
    }
    for (int i = N; i >= 1; --i) {
      ft[i] = ft[i] - ft[i - lsb(i)];
    }
  }
  T query(int p) const {
    T res = T();
    for (; p >= 1; p -= lsb(p)) {
      res = res + ft[p];
    }
    return res;
  }
  T query(int l, int r) const {
    return query(r) - query(l);
  }
  void update(int p, T value) {
    for (++p; p <= N; p += lsb(p)) {
      ft[p] = ft[p] + value;
    }
  }
};

template <typename T>
struct ColorfulOperations {
  std::map<int, int> color;
  BIT<T> bit;
  std::vector<T> offset;
  ColorfulOperations(int N) : bit(N), offset(N) {
    color[N] = 0;
  }
  int query_color(int i) {
    return std::prev(color.upper_bound(i))->second;
  }
  void color_range(int l, int r, int c) {
    color[l] = query_color(l);
    color[r] = query_color(r);
    for (auto iter = color.find(l); iter->first < r; iter = color.erase(iter)) {
      int ll = iter->first, rr = std::next(iter)->first;
      int cc = iter->second;
      bit.update(ll, +offset[cc]);
      bit.update(rr, -offset[cc]);
    }
    color[l] = c;
    bit.update(l, -offset[c]);
    bit.update(r, +offset[c]);
  }
  void add(int c, T x) {
    offset[c] += x;
  }
  T query(int i) {
    return bit.query(i + 1) + offset[query_color(i)];
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  std::cin >> N >> Q;
  ColorfulOperations<int64_t> co(N);
  for (int q = 0; q < Q; ++q) {
    std::string S;
    std::cin >> S;
    if (S == "Color") {
      int l, r, c;
      std::cin >> l >> r >> c;
      --l, --c;
      co.color_range(l, r, c);
    } else if (S == "Add") {
      int c, x;
      std::cin >> c >> x;
      --c;
      co.add(c, x);
    } else {
      int i;
      std::cin >> i;
      --i;
      std::cout << co.query(i) << '\n';
    }
  }
  exit(0);
}