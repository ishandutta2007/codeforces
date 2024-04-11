#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

template <class T>
struct fenwick_tree {

  T tree[N];

  void update(int a, T val) {
    for ( ; a < N; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  T query(int a, int b) {
    return query(b) - query(a - 1);
  }

};

fenwick_tree<int> ft;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int cnt = n % 2;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnt ^= ft.query(a, n) % 2;
    ft.update(a, 1);
  }
  cout << (cnt == 1 ? "Um_nik" : "Petr") << "\n";
}