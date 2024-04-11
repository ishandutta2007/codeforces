#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void run_case() {
  int N, M, x, y;
  cin >> N >> M >> x >> y;
  if (x == 1 && y == 1) {
    cout << 1 << " " << M << " " << N << " " << 1 << "\n";
    return;
  }
  if (x == N && y == 1) {
    cout << 1 << " " << 1 << " " << N << " " << M << "\n";
    return;
  }
  if (x == N && y == M) {
    cout << 1 << " " << M << " " << N << " " << 1 << "\n";
    return;
  }
  if (x == 1 && y == M) {
    cout << 1 << " " << 1 << " " << N << " " << M << "\n";
    return;
  }
  cout << 1 << " " << 1 << " " << N << " " << M << "\n";
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--)
    run_case();
}