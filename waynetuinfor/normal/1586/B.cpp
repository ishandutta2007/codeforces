#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<bool> is_b(N);
    for (int i = 0; i < M; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      is_b[b - 1] = true;
    }
    int root = 0;
    while (is_b[root]) root++;
    for (int i = 0; i < N; ++i) {
      if (i != root) {
        cout << root + 1 << " " << i + 1 << "\n";
      }
    }
  }
}